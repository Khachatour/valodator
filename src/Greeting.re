let component = ReasonReact.statelessComponent("Greeting");

[@bs.module] external logo : string = "./static/logo.png";

let make = _children => {
  ...component,
  render: _self =>
    <div className="greeting">
      <p>
        (ReasonReact.stringToElement("Made with " ++ {js|❤️|js} ++ " at "))
        <a href="https://www.renderforest.com">
          (ReasonReact.stringToElement("Renderforest"))
        </a>
      </p>
      <img src=logo />
    </div>
};