This patch adds support for CSS `text-shadow` and `letter-spacing`.
Shadows are rendered as simple offset text with blur ignored if the platform
does not provide shadow APIs. Letter spacing is applied during width
calculation and drawing. RTL text simply subtracts spacing.
