type action =
  | Change(string)
  | KeyDown;

type state = {text: string};

let component = ReasonReact.reducerComponent("CommitField");

let make = _children => {
  ...component,
  initialState: () => {text: ""},
  reducer: (action, state) =>
    switch action {
    | Change(text) => ReasonReact.Update({text: text})
    | KeyDown =>
      Js.log(state);
      ReasonReact.NoUpdate;
    },
  render: self =>
    <div className="commit-field">
      <p>
        (
          ReasonReact.stringToElement(
            "Copy and paste your commit message to validate!"
          )
        )
      </p>
      <textarea
        rows=12
        cols=24
        value=self.state.text
        onKeyDown=(_e => self.send(KeyDown))
        onChange=(
          e =>
            self.send(
              Change(
                ReactDOMRe.domElementToObj(ReactEventRe.Form.target(e))##value
              )
            )
        )
      />
      <button className="valodate-button">
        (ReasonReact.stringToElement("valodate"))
      </button>
    </div>
};