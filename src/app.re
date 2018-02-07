[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <p className="App-intro"> (ReasonReact.stringToElement("Valodator")) </p>
    </div>
};