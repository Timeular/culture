# Culture

Get the current user date and time locale and allows to open the date/time system preferences.

*works on windows and mac*

## Doc

```typescript
// returns the current user locale (e.g. en-us, en-gb, de-de, ...)
culture.get() : string
// opens the date/time system preferences
culture.openSettings()
```

## Example

```javascript
const culture = require('culture');
const locale = culture.get(); // e.g. en-us
culture.openSettings();
```