[%bs.raw {|require('./App.css')|}];
[%bs.raw {|require('./reset.css')|}];

[@bs.module] external logo: string = "./logo.svg";

type role = {
  title: string,
  icon: string,
  id: string,
};

type teamMember = {
  role,
  tjm: int,
  daysStaffed: float,
};

let roles: array(role) = [|
  {title: "Dev", icon: {js|👨‍💻|js}, id: "dev"},
  {title: "Archi-Dev", icon: {js|👩‍🏫|js}, id: "archi"},
  {title: "Agile Coach", icon: {js|🕵️‍|js}, id: "ca"},
  {title: "UX Design", icon: {js|👩‍🎨|js}, id: "ux"},
  {title: "Project Mgmt", icon: {js|🤵|js}, id: "dp"},
|];

type state = {members: list(teamMember)};
type action =
  | AddMember(teamMember);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {members: []},
  reducer: (action, state) =>
    switch (action) {
    | AddMember(member) =>
      ReasonReact.Update({members: state.members @ [member]})
    },
  render: self =>
    <div className="App">
      <h1> {ReasonReact.string("Easy TJM")} </h1>
      {
        ReasonReact.array(
          Array.map(
            role =>
              <button
                key={role.id}
                onClick={
                  _ => self.send(AddMember({role, tjm: 0, daysStaffed: 5.}))
                }>
                <div> {ReasonReact.string(role.icon)} </div>
                <span> {ReasonReact.string(role.title)} </span>
              </button>,
            roles,
          ),
        )
      }
      <table>
        <thead> <tr> <th> {ReasonReact.string("Role")} </th> </tr> </thead>
        <tbody>
          {
            ReasonReact.array(
              Array.map(
                member =>
                  <tr>
                    <td> {ReasonReact.string(member.role.icon)} </td>
                  </tr>,
                Array.of_list(self.state.members),
              ),
            )
          }
        </tbody>
      </table>
    </div>,
};
