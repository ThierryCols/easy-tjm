[%bs.raw {|require('./App.css')|}];
[%bs.raw {|require('./reset.css')|}];

[@bs.module] external logo: string = "./logo.svg";

type state = {members: list(Team.teamMember)};
type action =
  | AddMember(Team.teamMember);

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
      <div className="btn-subtitles">
        <h3> {ReasonReact.string("I want a...")} </h3>
      </div>
      <div className="btn-container">
        {
          ReasonReact.array(
            Array.map(
              (role: Team.role) =>
                <RoleButton
                  role
                  clickHandler={
                    _ =>
                      self.send(AddMember({role, tjm: 0, daysStaffed: 5.}))
                  }
                />,
              Team.roles,
            ),
          )
        }
      </div>
      <MembersTable members={self.state.members} />
    </div>,
};
