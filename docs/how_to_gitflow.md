# How to gitflow

gitflow is a development method using git

under no circumstances you should push change on branch
- `master`
- `develop`
use Pull request for that

## How it works

- [new feature](#new-feature)
- [release](#new-release)
- [bug](#bug)

### New Feature

When you whant to add new feature you create a branch named `feature/NAME_OF_YOUR_BRANCH`. when you finish your feature, you create a [Pull Request](https://github.com/doliG/corewar/pulls) to the `develop` branch

### New Release

After all the hard work, you whant to release a new version of your project.

for that you new to create a branch from `develop` named `release/vX.X.X` make your test and change in that branch. when its done create a [Pull Request](https://github.com/doliG/corewar/pulls) to `master`.

> Don't forget to create a tag for this version, see [git tag](https://git-scm.com/book/en/v2/Git-Basics-Tagging)

### Bug

When you found a bug create a new `issue` to [github](https://github.com/doliG/corewar/issues).
- If you work on correcting a issue from the `master` branch create a branch named `hotfix/NAME_OF_YOUR_BRANCH` from it.
When its done create 2 PR one for `master` the other for `develop`
- If you work on correcting a issue from the `develop` branch create
a branch like it was a [feature](#new-feature)
