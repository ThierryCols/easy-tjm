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
  {title: "UX Designer", icon: {js|👩‍🎨|js}, id: "ux"},
  {title: "Project Director", icon: {js|🤵|js}, id: "dp"},
|];
