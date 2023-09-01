// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

namespace Glib {
class ustring;
class VariantBase;
} // namespace Glib

class QWindow;

namespace base::Platform::XDP {

inline constexpr auto kService = "org.freedesktop.portal.Desktop";
inline constexpr auto kObjectPath = "/org/freedesktop/portal/desktop";
inline constexpr auto kRequestInterface = "org.freedesktop.portal.Request";
inline constexpr auto kSettingsInterface = "org.freedesktop.portal.Settings";

Glib::ustring ParentWindowID();
Glib::ustring ParentWindowID(QWindow *window);

std::optional<Glib::VariantBase> ReadSetting(
	const Glib::ustring &group,
	const Glib::ustring &key);

class SettingWatcher {
public:
	SettingWatcher(
		Fn<void(
			const Glib::ustring &,
			const Glib::ustring &,
			const Glib::VariantBase &)> callback);

	~SettingWatcher();

private:
	class Private;
	const std::unique_ptr<Private> _private;
};

} // namespace base::Platform::XDP
