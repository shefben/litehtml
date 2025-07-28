This patch adds support for CSS `text-shadow`, `letter-spacing`, and `box-shadow`.
Text shadows and box shadows are rendered using basic canvas effects with blur
ignored when the platform lacks shadow APIs. Letter spacing is applied during
width calculation and drawing. RTL text simply subtracts spacing.
