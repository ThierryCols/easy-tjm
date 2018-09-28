let component = ReasonReact.statelessComponent("MembersTable");

let make = (~members, _children) => {
  ...component,
  render: _self =>
    <table>
      <thead> <tr> <th> {ReasonReact.string("Role")} </th> </tr> </thead>
      <tbody>
        Team.(
          ReasonReact.array(
            Array.map(
              member =>
                <tr> <td> {ReasonReact.string(member.role.icon)} </td> </tr>,
              Array.of_list(members),
            ),
          )
        )
      </tbody>
    </table>,
};
