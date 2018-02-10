type action =
  | Change(string);

type state = {text: string};

let component = ReasonReact.reducerComponent("MyForm");

let make = _children => {
  ...component,
  initialState: () => {text: ""},
  reducer: (action, _state) =>
    switch action {
    | Change(text) =>
      Js.log(text);
      ReasonReact.Update({text: text});
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
        onChange=(
          e =>
            self.send(
              Change(
                ReactDOMRe.domElementToObj(ReactEventRe.Form.target(e))##value
              )
            )
        )
      />
    </div>
};