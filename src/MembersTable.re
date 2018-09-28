let component = ReasonReact.statelessComponent("MembersTable");

let make = (~members, _children) => {
  ...component,
  render: _self =>
    <table className="members-table">
      <thead>
        <tr>
          <th> {ReasonReact.string("Role")} </th>
          <th> {ReasonReact.string("Days Staffed per Week")} </th>
          <th> {ReasonReact.string("Rate")} </th>
        </tr>
      </thead>
      <tbody>
        Team.(
          ReasonReact.array(
            Array.map(
              member =>
                <tr>
                  <td> {ReasonReact.string(member.role.icon)} </td>
                  <td>
                    {ReasonReact.string(string_of_float(member.daysStaffed))}
                  </td>
                  <td> {ReasonReact.string(string_of_int(member.tjm))} </td>
                </tr>,
              Array.of_list(members),
            ),
          )
        )
      </tbody>
    </table>,
};
