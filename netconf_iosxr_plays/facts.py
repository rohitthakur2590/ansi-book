---
- hosts: iosxr
  gather_facts: false
  tasks:
  - iosxr_facts:
      gather_subset: all
