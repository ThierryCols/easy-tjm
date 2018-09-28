let component = ReasonReact.statelessComponent("RoleButton");

let make = (~role: Team.role, ~clickHandler, _children) => {
  ...component,
  render: _self =>
    <button className="role-btn" key={role.id} onClick=clickHandler>
      <div className="btn-icon"> {ReasonReact.string(role.icon)} </div>
      <span className="btn-label"> {ReasonReact.string(role.title)} </span>
    </button>,
};
