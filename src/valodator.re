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
  render: self => {
    let message = "You just typed: " ++ self.state.text;
    <div>
      <input
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
      (ReasonReact.stringToElement(message))
    </div>;
  }
};