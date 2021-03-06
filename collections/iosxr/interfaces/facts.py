---
- hosts: iosxr-rdo
  collections:
    - cisco.iosxr
  gather_facts: yes
  tasks:
    - name: facts
      iosxr_facts:
        gather_subset:
          - '!all'
          - '!min'
        gather_network_resources:
          - interfaces
