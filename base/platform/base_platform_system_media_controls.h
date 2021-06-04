// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

class QWidget;

namespace base::Platform {

class SystemMediaControls {
public:
	enum class Command {
		Play,
		Pause,
		Next,
		Previous,
		Stop,
		None,
	};

	enum class PlaybackStatus {
		Playing,
		Paused,
		Stopped,
	};

	SystemMediaControls();
	~SystemMediaControls();

	bool init(std::optional<QWidget*> parent);

	void setEnabled(bool enabled);
	void setIsNextEnabled(bool value);
	void setIsPreviousEnabled(bool value);
	void setIsPlayPauseEnabled(bool value);
	void setIsStopEnabled(bool value);
	void setPlaybackStatus(PlaybackStatus status);
	void setTitle(const QString &title);
	void setArtist(const QString &artist);
	void setThumbnail(const QImage &thumbnail);
	void clearThumbnail();
	void clearMetadata();
	void updateDisplay();

	[[nodiscard]] rpl::producer<Command> commandRequests() const;

	static bool Supported();

private:
	struct Private;

	const std::unique_ptr<Private> _private;

	rpl::event_stream<Command> _commandRequests;
};

} // namespace base::Platform
