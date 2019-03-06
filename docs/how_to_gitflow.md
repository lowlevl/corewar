# How to gitflow

Gitflow is a development method using git.

You must not push changes on branch:
- `master`
- `develop`

These branche will only accept PR (pull request).

## How it works

Git flow work with branches, a lot of branches:
- [feature/...](#new-feature)
- [release](#new-release)
- [bug](#bug)

### [Want to create a new feature](#new-feature)

When you want to add new feature, create a branch named `feature/NAME_OF_YOUR_BRANCH`. After finishing your feature, create a [Pull Request](https://github.com/doliG/corewar/pulls) to the `develop` branch

### [Want to create a new release ?](#new-release)

After all the hard work, you will probably want to release a new version of your project.

For that you need to create a branch from `develop` named `release/vX.X.X`, then run your test and if you need, you can do small fix in this branch.

When it's done, create a [Pull Request](https://github.com/doliG/corewar/pulls) to the branch `master`.

> Don't forget to create a tag for this version, see [git tag](https://git-scm.com/book/en/v2/Git-Basics-Tagging)

### [Found a bug ?](#bug)

When you find a bug, create a new `issue` [here](https://github.com/doliG/corewar/issues/new).

If you work on correcting an issue from` master`, create a branch named `hotfix/NAME_OF_YOUR_BRANCH` from `master`.

When its done, you have to **create 2 PR**: one for `master`, and the other for `develop`.

If you work on correcting an issue from `develop`, create a branch like it was a [feature](#new-feature).
