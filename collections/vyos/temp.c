 Start working on feature
$git checkout -b patch_branch_name upstream/devel

$git add lib/ansible/modules/network/asa/asa_config.py
$git commit -m "fix asa_config issue" -s 
 
$git push origin patch_branch_name

git remote set-url origin git@github.com:username/repo.git

In case ssh keys doesn’t work
git remote set-url origin git@github.com:username/repo.git


ROADMAP 
https://github.com/ansible/community/wiki/Network%3A-2.10-Roadmap



Synch a fork
$git fetch upstream
$git rebase upstream/asa_fix_changes

Update a fork
Git push -f origin devel


#git reset HEAD~2
git reset --hard origin/my_remote_tracking_branch (when nothing works)



CHECKIN A FIX 

$git fetch upstream
$git rebase upstream/devel
(NOTE that you would either need to stash or commit changed)^^
$git checkout -b patch_branch_name upstream/devel
$git status
(will show you modified/new files)
$git add -A (to add all modified/new files) or git add <file_name> (to add any particular modified/new file)
$git commit -m "Your commit message" -s
$git push -f origin patch_branch_name


$ansible-test sanity --tox --python 2.7 lib/ansible/modules/network/nxos/nxos_facts.


Py
ansible-test sanity --tox --python 2.7 lib/ansible/modules/network/vyos/vyos_linkagg.py

vyos_firewall_interfaces_model.yaml
ansible-test network-integration --inventory test-inventory vyos_lag_interfaces

RMB : 
 ansible-playbook -e rm_dest=/home/rothakur/dev-workspace/sr_test -e structure=role -e model=/home/rothakur/dev-workspace/resource_module_models/models/vyos/static_routes/vyos_static_route.yaml site.yml

ansible-playbook -e rm_dest=~/dev-workspace/rr_test -e structure=collection -e collection_org=vyos -e collection_name=vyos -e model=~/dev-workspace/resource_module_models/models/vyos/ospfv2/vyos_ospf.yaml site.yml -vvv

Auto Hold
Zuul debug
dmellado@zs01:~$ sudo -H -u zuul /opt/venv/zuul/bin/zuul autohold --tenant ansible --project ansible/ansible --job ansible-test-network-integration-vyos-python37 --reason 'rthakur_vyos_debugging'

To see
sudo -H -u nodepool /opt/venv/nodepool-3.12.0/bin/nodepool -s /etc/nodepool/secure.conf list | grep hold
ansible-collections/vyos
i
Zuul login
ssh root@74.63.204.88
that's the controller machine
then su - zuul





RUN Integration test on controller node
/home/zuul/.ansible/collections/ansible_collections/vyos/vyos
(venv) zuul@ubuntu-bionic-1vcpu-vexxhost-ca-ymq-1-0000368480:~/.ansible/collections/ansible_collections/vyos/vyos$ ansible-test network-integration --diff --no-temp-workdir --skip-tags False --inventory ~/inventory --continue-on-error --python 3.8 -vvvv vyos_.*








https://dashboard.zuul.ansible.com/t/ansible/builds?pipeline=periodic&branch=devel
$Open the issue -> In right hand pane you'll see `Projects`, choose `Networking` in it.
Then click on that project board 	
By default it'll be in `Needs Triage` list
Move it to `In Review`

 

 <git bug board process>
The process is, once you have been assigned a bug, and you have confirmed that it is actually a bug, add it to the Networking Project board and move it to `In Progress` when you start working on it.
Once you have raised the PR move it to `In Review`
Once it's merged move it to `Done`



RESOURCE MODULE 
$git clone git@github.com:rohitthakur2590/network.git
$git remote add upstream https://github.com/ansible/network 	
$git fetch upstream
$git rebase upstream/devel
$git fetch upstream pull/4/head:vyos_interfaces

https://github.com/ansible/ansible/pull/58589/head:vyos_interfaces

https://www.youtube.com/watch?v=AVYfyTvc9KY


$git clone git@github.com:rohitthakur2590/network.git










 
etc/yum.repos.d/
Cherry-Pick
 Pull Your commit on Devel after merge
 $git remote -v 

origin    git@github.com:rohitthakur2590/ansible.git (fetch)
origin    git@github.com:rohitthakur2590/ansible.git (push)
upstream    https://github.com/ansible/ansible (fetch)
upstream    https://github.com/ansible/ansible (push)
 
$git fetch upstream
    Above  will pull all the commits merged on devel (edited) 

 
 
$git rebase upstream/devel
    what above command  will do is, rebase the commits from ansible repo to your local devel    branch which were recently merged fetched from the previous command
this is how you can keep your branch updated or in sync with ansible devel (edited) 

 
 
now to cherry-pick to 2.8
what you need to do is
create `stable-2.8` locally
then
$ git checkout stable-2.8

 
 
$git rebase upstream/stable-2.8
      <this will rebase your local stable-2.8 branch with ansible one ,this is act as default 2.8          branch like you are using devel
don't open PRs from stable-2.8>

$git checkout stable-2.8
    <so open PR, you need to create another branch from stable-2.8
, this makes sure that you are on 2.8 before creating a branch for cherry-pick>
then

$git checkout -b asa_config_fix28_backport
 <this branch will have all the commits that stable-2.8 has but not devel (edited) 
let me know when you are done>


$git cherry-pick -x <commitid> 
<your commit sha would be
`06c050e9bd7ab467dd6c10ed073928778c4b1b41`
the one from here https://github.com/ansible/ansible/commit/06c050e9bd7ab467dd6c10ed073928778c4b1b41
you can use just the first few letters also from commit id. minimum 7>


 
$ cd changelogs/fragments
 < now for each backport we need to write changelog >

 
 
<now create a yaml file>
with some name like asa_config_fixbackport.yaml
or something
The content would be:
```bugfixes:
- asa_config fix <https://github.com/ansible/ansible/pull/56559>```
(edited)
one line description for the commit


now add and commit this file
and push to github
 

 
we don't write changelog if the change is related to test changes or documentation
just fyi

 
 
so fot this yaml file git push command will be
$git add <asa_config_fixbackport.yaml>
$git commit -m “backport” -s 
$ git push -f origin asa_config_fix28_backport

 <
this will push
your cherry-picked commit and the file you added
both>

 

 
now similar you'll have to go to github
only difference is
instead of opening the PR against devel, open it against stable-2.8

 

trishnag [12:38 PM]
go to your branch and click on open pull request
then you'll have option to select like in the image you shared earlier, it is `base:devel` for ansible/ansible (edited) 
change that to stable-2.8

 

VM SET UP

Start VM BOx
ADD INTERFACES FROM  NETWORK 
  <first interface should be netwrok host adapter, rest will be internal >
Add ip address to interfaces
Add ssh ipaddress
Add ssh enable  
- Commit configuration 







    git config --global --edit

After doing this, you may fix the identity used for this commit with:

    git commit --amend --reset-author

Folks, is there a way to check startup-config (/config/config.boot) in set format?

runborg [2:21 PM]
go into config mode and enter `cat /config/config.boot | commands`




To: rhexpenses@redhat.com
Subject: 
Paste barcode ID in the subject line
Do not put anything else in the subject line, just this barcode
Attachment: Attach a PDF of your receipts
Attachment must be a PDF
Use CUPS-PDF printer or pdfconvert@redhat.com to create the PDF
Do not password protect the PDF
You must attach your receipts within 5 days
Body: Do not type any message in the body of the email
DTID-21$CPID-1961922\


def merge_two_dicts(dict1, dict2):
   dict = dict1.copy()   # start with dict1's keys and values
   dict.update(dict2)    # modifies dict with dict2's keys and values & returns None
   return dict

