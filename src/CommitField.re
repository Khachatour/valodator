type action =
  | Change(string)
  | KeyDown(int);

type state = {
  text: string,
  valid: bool
};

let str = ReasonReact.stringToElement;

let component = ReasonReact.reducerComponent("CommitField");

let make = _children => {
  ...component,
  initialState: () => {text: "", valid: false},
  reducer: (action, state) =>
    switch action {
    | Change(text) => ReasonReact.Update({...state, text})
    | KeyDown(num) =>
      if (num === 13) {
        let checkForValidCommit: state => bool = [%bs.raw
          {|function (state) {
            const strToMatch = state[0]
            const regexToMatch = /[a-z\(\)#]+:[a-z\s]+\n*(\-?\s+[a-z\sA-Z\.]+){0,10}/g
            return !!strToMatch.match(regexToMatch)
        }|}
        ];
        let isCommitValid = checkForValidCommit(state);
        Js.log(isCommitValid);
        ReasonReact.Update({...state, valid: isCommitValid});
      } else {
        ReasonReact.NoUpdate;
      }
    },
  render: ({state, send}) => {
    Js.log(state);
    <div className="commit-field">
      <p> (str("Copy and paste your commit message to validate!")) </p>
      (
        string_of_bool(state.valid) === "true" ?
          <p> (str("Your commit is Valod")) </p> : <p> (str("Not Valod")) </p>
      )
      <textarea
        rows=12
        cols=24
        value=state.text
        onKeyDown=(e => send(KeyDown(ReactEventRe.Keyboard.which(e))))
        onChange=(
          e =>
            send(
              Change(
                ReactDOMRe.domElementToObj(ReactEventRe.Form.target(e))##value
              )
            )
        )
      />
      <button className="valodate-button"> (str("valodate")) </button>
    </div>;
  }
};