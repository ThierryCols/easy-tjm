let component = ReasonReact.statelessComponent("RoleButton");

let make = (~role: App.role, ~clickHandler, _children) => {
  ...component,
  render: _self =>
    <button key={role.id} onClick=clickHandler>
      <span> {ReasonReact.string(role.title)} </span>
    </button>,
};
