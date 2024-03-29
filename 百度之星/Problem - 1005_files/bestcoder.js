Number.prototype.toFixedLength = function (length) {
	var fixedLengthNumber = this.toString(),
		needPad = length - fixedLengthNumber.length;
	while (needPad > 0) {
		needPad--;
		fixedLengthNumber = '0' + fixedLengthNumber;
	}
	return fixedLengthNumber;
};

var $sourceModal = $('#source-modal'),
	$modalTitle = $sourceModal.find('.modal-title'),
	$modalBody = $sourceModal.find('.modal-body > pre'),
	$modalFooter = $sourceModal.find('.modal-footer'),
	$closeButton = $('<button type="button" class="btn btn-default" data-dismiss="modal">Close</button>'),
	$messageBox = $('<ul id="message-box" class="list-group"><li class="list-group-item list-group-header"><button type="button" class="close" data-dismiss="#message-box">&times;</button></li></ul>').appendTo('body').hide(),
	$messageBoxHeader = $messageBox.find('.list-group-header'),
	$progressContainer = $('<div class="container"><div class="progress progress-striped active"><div class="progress-bar progress-bar-success"><span></span></div></div></div>').insertAfter('.navbar-inverse:first').find('.progress').hide(),
	$progressBar = $progressContainer.find('.progress-bar');

function getError(cid, rid){
	$.get("getAjaxInfo.php?act=viewerror&cid=" + cid + "&rid=" + rid, function (data) {
		$modalTitle.text("Compilation Error");
		if (data) {
			$modalBody.text(data);
		} else {
			$modalBody.text('No compilation error message available');
		}
		$modalFooter.empty().append($closeButton);
		$sourceModal.modal();
	});
}

function getCode(cid, rid) {
	var styles = ['default', 'rainbow', 'atelier', 'paper', 'foundation', 'github', 'monokai', 'xcode'];
	var defaultStyle = $.cookie('code-style') || 'default';
	$.get("getAjaxInfo.php?act=viewcode&cid=" + cid + "&rid=" + rid, function (data) {
		data = data.replace(/</g, "&lt;").replace(/>/g, "&gt;");
		var $select = $modalTitle.find('select');
		if (!$select.length) {
			$modalTitle.text("Source Code");
			$('<span id="code-style">Style: <select></select></span>').appendTo($modalTitle);
			$select = $modalTitle.find('select');
			$.each(styles, function (index, styleName) {
				if (styleName == defaultStyle) {
					$('<option value="' + styleName + '" selected="selected">' + styleName + '</option>').appendTo($select);
				} else {
					$('<option value="' + styleName + '">' + styleName + '</option>').appendTo($select);
				}
			});
			$select.change(function () {
				$('link[href*="/assets/styles/"]').attr('href', '/assets/styles/' + $(this).val() + '.css');
				$.cookie('code-style', $(this).val(), {expires: 999999, path: '/'});
			});
		}
		$modalBody.html('<code>' + data +'</code>');
		if (typeof hljs == 'object') {
			hljs.highlightBlock($modalBody[0]);
		}
		$modalFooter.empty().append($closeButton);
		$sourceModal.modal();
	});
}

function getFlash(cid, rid, check) {
	var styles = ['default', 'rainbow', 'atelier', 'paper', 'foundation', 'github', 'monokai', 'xcode'],
		defaultStyle = $.cookie('code-style') || 'default',
		$select = $modalTitle.find('select');
	if (!$select.length) {
		$modalTitle.text("Source Code");
		$('<span id="code-style">Style: <select></select></span>').appendTo($modalTitle);
		$select = $modalTitle.find('select');
		$.each(styles, function (index, styleName) {
			if (styleName == defaultStyle) {
				$('<option value="' + styleName + '" selected="selected">' + styleName + '</option>').appendTo($select);
			} else {
				$('<option value="' + styleName + '">' + styleName + '</option>').appendTo($select);
			}
		});
		$select.change(function () {
			$('link[href*="/assets/styles/"]').attr('href', '/assets/styles/' + $(this).val() + '.css');
			$('#viewcode').attr('data', 'http://bestcoder.hdu.edu.cn/contests/HackCode.swf?rid=' + rid + '&cid=' + cid + '&width=600&height=' + ($(window).height() - 150) + '&codeStyle=' + $(this).val());
			$.cookie('code-style', $(this).val(), {expires: 999999, path: '/'});
		});
	}
	var flash = '<object id="viewcode" name="viewcode" type="application/x-shockwave-flash" width="600" height="' + ($(window).height() - 150) + '" data="http://bestcoder.hdu.edu.cn/contests/HackCode.swf?rid=' + rid + '&cid=' + cid + '&width=600&height=' + ($(window).height() - 150) + '&codeStyle=' + defaultStyle + '">' +
			'<param name="allowScriptAccess" value="always" />' +
			'<param name="quality" value="high" />' +
			'<param name="menu" value="false" />' +
			'<param name="wmode" value="transparent" />' +
			'<param name="movie" value="http://bestcoder.hdu.edu.cn/contests/HackCode.swf?rid=' + rid + '&cid=' + cid + '&width=600&height=' + ($(window).height() - 150) + '&codeStyle=' + defaultStyle + '" />' +
		'</object>';
	$modalFooter.empty().append($closeButton);
	if (check) {
		$.get('getAjaxInfo.php?act=check&cid=' + cid + "&rid=" + rid, function (hack) {
			if (hack == '1') {
				$modalFooter.append('<button onclick="doHack(' + cid + ', ' + rid + ')" type="button" class="btn btn-primary">Hack</button>');
			}
		});
	} else {
		$modalFooter.append('<button onclick="doHack(' + cid + ', ' + rid + ')" type="button" class="btn btn-primary">Hack</button>');
	}
	$modalBody.html(flash).css('padding', '0');
	$sourceModal.modal();
}

function doHack(cid, rid) {
	$modalFooter.empty();
	$modalFooter.append($('<span id="hack-error"></span>'));
	$modalFooter.append($closeButton);
	$modalFooter.append($('<button onclick="getFlash(' + cid + ', ' + rid + ')" type="button" class="btn btn-primary">Source</button><button onclick="doPost(' + cid + ',' + rid + ')" type="button" class="btn btn-primary">Submit</button>'));
	$modalBody.html('<textarea class="form-control" id="data-text"></textarea>').find('#data-text').css('height', ($(window).height() - 150) + 'px');
	$sourceModal.modal();
}

function doPost(cid, rid) {
	$.post("getAjaxInfo.php?act=insert&cid=" + cid + "&rid=" + rid, {
		data: $("#data-text").val()
	}, function (error) {
		if (error) {
			$('#hack-error').text(error);
		} else {
			window.location.href = "contest_hackstatus.php?cid=" + cid;
		}
	});
}

function getData(cid, rid) {
	$.get("getAjaxInfo.php?act=viewdata&cid=" + cid + "&rid=" + rid, function (data) {
		$modalTitle.text("Hack Data");
		$modalBody.html(data);
		$modalFooter.empty().append($closeButton);
		$sourceModal.modal();
	});
}

function countdown() {
	var countdowns = $('.countdown:has(span)');
	$.each(countdowns, function () {
		var self = $(this),
			$hour = self.find('.hour'),
			hour = parseInt($hour.text(), 10),
			$minute = self.find('.minute'),
			minute = parseInt($minute.text(), 10),
			$second = self.find('.second'),
			second = parseInt($second.text(), 10);
		if (hour || minute || second) {
			second--;
			if (second < 0) {
				second += 60;
				minute--;
			}
			$second.text(second.toFixedLength(2));
			if (minute < 0) {
				minute += 60;
				hour--;
			}
			$minute.text(minute.toFixedLength(2));
			$hour.text(hour.toFixedLength(2));
		} else {
			setTimeout(function () {
				document.location.reload();
			}, 3000);
		}
	});
	setTimeout(function () {
		countdown();
	}, 1000);
}

function levelColor(rating) {
	rating = parseInt(rating);
	if (rating === 0) {
		return 'level0';
	} else if (rating > 0 && rating < 1100) {
		return 'level1';
	} else if (rating >= 1100 && rating < 1300) {
		return 'level2';
	} else if (rating >= 1300 && rating < 1500) {
		return 'level3';
	} else if (rating >= 1500 && rating < 1700) {
		return 'level4';
	} else if (rating >= 1700 && rating < 1900) {
		return 'level5';
	} else if (rating >= 1900 && rating < 2100) {
		return 'level6';
	} else if (rating >= 2100 && rating < 2300) {
		return 'level7';
	} else if (rating >= 2300 && rating < 2500) {
		return 'level8';
	} else {
		return 'level9';
	}
}

function clock() {
	var clocks = $('.clock:has(span)');
	$.each(clocks, function () {
		var self = $(this),
			$hour = self.find('.hour'),
			hour = parseInt($hour.text(), 10),
			$minute = self.find('.minute'),
			minute = parseInt($minute.text(), 10),
			$second = self.find('.second'),
			second = parseInt($second.text(), 10);

		second++;
		if (second >= 60) {
			second -= 60;
			minute++;
		}
		$second.text(second.toFixedLength(2));
		if (minute >= 60) {
			minute -= 60;
			hour++;
		}
		$minute.text(minute.toFixedLength(2));
		$hour.text(hour.toFixedLength(2));
	});
	setTimeout(function () {
		clock();
	}, 1000);
}

function getMsg(cid, localCall) {
	$.getJSON('/api/api.php?type=contest-push-message&cid=' + cid, function (data) {
		if (data.stop) {
			return;
		}
		var messages = [];
		if (data.hackStartTime < data.serverTime) {
			messages.push({
				message: 'Hack time now, just hack it!',
				time: data.hackStartTime
			});
		}
		if (data.contestStartTime < data.serverTime) {
			messages.push({
				message: data.contestName + ' Start.',
				time: data.contestStartTime
			});
		}
		if (data.submitEndTime < data.serverTime) {
			messages.push({
				message: 'Submit end, wait for hack time.',
				time: data.submitEndTime
			});
		}
		if (data.contestEndTime < data.serverTime) {
			messages.push({
				message: 'Contest ended, wait for the rating update.',
				time: data.contestEndTime
			});
		}
		data.contestNotification.forEach(function (n) {
			messages.push({
				message: '<a href="contest_viewnotify.php?cid=' + cid + '&id=' + n.notiid + '">' + n.title + '</a>',
				time: n.time
			});
		});
		messages.sort(function (a, b) {
			return a.time < b.time;
		});

		var i, lastUpdateTime = $.cookie('contest-message-' + cid), pushLastUpdateTime = 0, noticeLastUpdateTime = 0;
		if (lastUpdateTime) {
			lastUpdateTime = lastUpdateTime.split(':');
			pushLastUpdateTime = lastUpdateTime[0];
			if (lastUpdateTime[1]) {
				noticeLastUpdateTime = lastUpdateTime[1];
			}
		}
		if (localCall) {
			for (i = 0; i < messages.length; i++) {
				if (messages[i].time <= pushLastUpdateTime) {
					break;
				}
			}
			while (i--) {
				var humanTime = new Date();
				humanTime.setTime(messages[i].time * 1000);
				$('<li class="list-group-item">' + messages[i].message + '<span class="time">' + humanTime.getHours().toFixedLength(2) + ':' + humanTime.getMinutes().toFixedLength(2) + '</span></li>').insertAfter($messageBoxHeader);
			}
		} else {
			$messageBoxHeader.prepend($('<span>' + data.contestName + '</span>'));
			messages.forEach(function (m) {
				var humanTime = new Date();
				humanTime.setTime(m.time * 1000);
				$('<li class="list-group-item">' + m.message + '<span class="time">' + humanTime.getHours().toFixedLength(2) + ':' + humanTime.getMinutes().toFixedLength(2) + '</span></li>').appendTo($messageBox);
			});
		}
		var nearestMessageTime = messages.length ? messages[0].time : 0;
		if (nearestMessageTime > pushLastUpdateTime && data.serverTime - nearestMessageTime < 60 * 60) { // the message box will open if the last message post in an hour
			$messageBox.slideDown();
		}
		$.cookie('contest-message-' + cid, nearestMessageTime + ':' + noticeLastUpdateTime, { expires: 7, path: '/' });

		// handle the judge progress bar
		if (data.judgeProgress != -1) {
			if (!data.rated) {
				$progressContainer.show();
				$progressBar.css('width', (data.judgeProgress * 100) + '%');
				$progressBar.text('Final Test Running: ' + Math.round(data.judgeProgress * 100) + '%');
				if (data.stopTime > 4 && data.judgeProgress != 1)
					data.stopTime = 4;
			} else {
				$progressContainer.hide();
			}
		} else {
			$progressContainer.hide();
		}

		setTimeout(function () {
			getMsg(cid, 1);
		}, data.stopTime * 1000);
	});
}

$(document).ready(function() {
	// add global data-dismiss handler
	$('[data-dismiss*=#]').click(function (event) {
		event.preventDefault();
		var closeElement = $(this).attr('data-dismiss');
		if (/^#/.test(closeElement)) {
			$(this).parents(closeElement).slideUp();
		}
	});
	// add code stylesheet
	var codeStyle = $.cookie('code-style') || 'default';
	$('<link rel="stylesheet" href="/assets/styles/' + codeStyle + '.css" type="text/css">').appendTo($('head'));

	//display system message if necessary
	$('#global-message').each(function () {
		var self = $(this),
			pubTime = self.attr('data-date'),
			lastUpdateTime = parseInt($.cookie('global-message'));
		if (pubTime > lastUpdateTime) {
			self.show();
		}
		// system message close handler
		self.children('.close').click(function (event) {
			$.cookie('global-message', pubTime, {expires: 365, path: '/'});
		});
	});
	//display contest message if necessary
	$('#contest-message').each(function () {
		var self = $(this),
			pubTime = self.attr('data-date'),
			contestid = self.attr('data-contestid'),
			lastUpdateTime = $.cookie('contest-message-' + contestid), pushLastUpdateTime = 0, noticeLastUpdateTime = 0;

		if (lastUpdateTime) {
			lastUpdateTime = lastUpdateTime.split(':');
			pushLastUpdateTime = lastUpdateTime[0];
			if (lastUpdateTime[1]) {
				noticeLastUpdateTime = lastUpdateTime[1];
			}
		}
		if (pubTime > noticeLastUpdateTime) {
			self.show();
		}

		// contest message close handler
		self.children('.close').click(function (event) {
			var $message = $(this).parent();
			$.cookie('contest-message-' + contestid, pushLastUpdateTime + ':' + pubTime, {expires: 7, path: '/'});
		});
	});
	// countdown component handler
	$('.countdown').each(function () {
		var self = $(this),
			$seconds = parseInt(self.text());
		if (isNaN($seconds))
			return;
		var $hours = Math.floor($seconds / 3600);
		var $minutes = Math.floor(($seconds - $hours * 3600) / 60);
		$seconds = $seconds % 60;

		self.html('<span class="hour">' + $hours + '</span> : ' + '<span class="minute">' + $minutes + '</span> : ' + '<span class="second">' + $seconds + '</span>').show();
	});
	countdown();
	// clock component handler
	$('.clock').each(function() {
		var self = $(this),
			now = new Date(),
			today = new Date(now.getFullYear(), now.getMonth(), now.getDate()),
			$seconds = parseInt(self.text());
		if (isNaN($seconds))
			return;
		$seconds = $seconds - Math.floor(today.getTime() / 1000);
		var $hours = Math.floor($seconds / 3600);
		var $minutes = Math.floor(($seconds - $hours * 3600) / 60);
		$seconds = $seconds % 60;

		self.html('<span class="hour">' + $hours + '</span>:' + '<span class="minute">' + $minutes + '</span>:' + '<span class="second">' + $seconds + '</span>').show();
	});
	clock();

	// render LaTex with  KaTex if the boswer not IE 8 / 7 / 6
	if (!$('html').hasClass('lt-ie9')) {
		renderMathInElement(document.body, {
			delimiters: [{ left: '\\[', right: '\\]', display: false }, { left: '$', right: '$', display: false }, { left: '\\(', right: '\\)', display: true }, { left: '$$', right: '$$', display: true }]
		});
	}
	// setup markdown highlight handler
	//marked.setOptions({
	//	highlight: function (code) {
    //		return hljs.highlightAuto(code).value;
  	//	}
	//});
	// render markdown with marked.js
	$('.markdown').each(function(index, md) {
		var self = $(this);
		self.html(marked(self.html().trim())).addClass('marked');
		if (typeof hljs == 'object') {
			$('[class*="lang-"]').each(function () {
				hljs.highlightBlock(this);
			});
		}
	});
	// add style to empty table
	$('table').each(function(index, tbody) {
		var self = $(this);
		if (self.find('td').length === 0) {
			self.after('<div class="no-data">No Data</div>');
		}
	});
	
	var clipboard = new Clipboard('button.copy');
	clipboard.on('success', function(e) {
		e.clearSelection();
	});
	clipboard.on('error', function(e) {
	});
});
