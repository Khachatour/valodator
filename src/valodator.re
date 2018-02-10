let component = ReasonReact.statelessComponent("Valodator");

let make = _children => {
  ...component,
  render: _self =>
    <div className="App-intro">
      <p> (ReasonReact.stringToElement("Valodator")) </p>
    </div>
};