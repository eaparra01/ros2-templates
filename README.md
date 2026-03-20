# ROS2 Templates

This repository provides **basic templates for ROS 2 nodes** implemented in both **Python** and **C++**. It is intended to serve as a starting point for quickly creating new ROS 2 packages and nodes following common conventions.

---

## 🚀 Features

- 📦 Ready-to-use ROS 2 package structure  
- 🐍 Python node template (`rclpy`)  
- ⚙️ C++ node template (`rclcpp`)  
- 🧱 Standardized folder organization  
- 🔧 Pre-configured build files (CMake / setup.py)  
- 🧪 Minimal examples to get started quickly  

---

## 📁 Repository Structure
```text
ros2-templates/
│── cpp_template/
│   ├── src/
│   ├── include/
│   ├── CMakeLists.txt
│   └── package.xml
│
│── python_template/
│   ├── package_name/
│   ├── setup.py
│   ├── setup.cfg
│   └── package.xml
│
└── README.md
```

## 🛠️ Requirements

- ROS 2 (Humble or newer recommended)
- Python 3
- C++17 compatible compiler
- colcon build tool

---

## ⚡ Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/eaparra01/ros2-templates.git
cd ros2-templates
```
### 2. Copy a template

- Choose the template you want:

- ```cpp_template/``` → for C++ nodes

- ```python_template/``` → for Python nodes

Copy it into your ROS 2 workspace:
```bash
cp -r cpp_template ~/ros2_ws/src/my_package
```

### 3. Rename the package

Update:

- Package name

- Node name

- Namespace (if needed)

Edit the following files accordingly:

- ```package.xml```

- ```CMakeLists.txt``` (C++)

- ```setup.py``` (Python)

### 4. Build the workspace
```bash
cd ~/ros2_ws
colcon build
source install/setup.bash
```
### 5. Run the node
#### C++
```bash
ros2 run my_package my_node
```
#### Python
```bash
ros2 run my_package my_node
```
### 🧩 Customization

You can extend the templates to include:

- Publishers / Subscribers

- Services / Actions

- Parameters

- Launch files

###  🎯 Purpose

This repository is designed to:

- Speed up ROS 2 development

- Provide clean starting points

- Encourage best practices and consistent structure

### 🤝 Contributing

Contributions are welcome! Feel free to:

- Improve templates

- Add new examples

- Fix issues

### 📄 License

Specify your license here (e.g., MIT, Apache 2.0).

### 📬 Contact

Maintained by the repository author.
For issues or suggestions, open a GitHub issue.

### ⭐ Acknowledgements

Inspired by common ROS 2 package structures and template-based workflows used in robotics projects.
