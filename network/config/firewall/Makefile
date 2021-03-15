#
# Copyright (C) 2013-2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=firewall
PKG_VERSION:=2015-07-27
PKG_RELEASE:=$(PKG_SOURCE_VERSION)

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=git://nbd.name/firewall3.git
PKG_SOURCE_BRANCH:=nbd/master
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=980b7859bbd1db1e5e46422fccccbce38f9809ab
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz
PKG_MAINTAINER:=Jo-Philipp Wich <jow@openwrt.org>
PKG_LICENSE:=ISC

ifneq ($(subst ",,${CONFIG_PROJECT_NAME}),)
TARGET_CFLAGS += \
	-D$(subst ",,${CONFIG_PROJECT_NAME})
endif

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/firewall
  SECTION:=net
  CATEGORY:=Base system
  TITLE:=OpenWrt C Firewall
  DEPENDS:=+libubox +libubus +libuci +libip4tc +IPV6:libip6tc +libxtables +kmod-ipt-core +kmod-ipt-conntrack +kmod-ipt-nat
endef

define Package/firewall/description
 This package provides a config-compatible C implementation of the UCI firewall.
endef

define Package/firewall/conffiles
/etc/config/firewall
/etc/firewall.user
endef

TARGET_CFLAGS += -ffunction-sections -fdata-sections -fpie
TARGET_LDFLAGS += -Wl,--gc-sections -pie
CMAKE_OPTIONS += $(if $(CONFIG_IPV6),,-DDISABLE_IPV6=1)

define Package/firewall/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/firewall3 $(1)/sbin/fw3
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/firewall.init $(1)/etc/init.d/firewall
	$(INSTALL_DIR) $(1)/etc/hotplug.d/iface
	$(INSTALL_DATA) ./files/firewall.hotplug $(1)/etc/hotplug.d/iface/20-firewall
	$(INSTALL_DIR) $(1)/etc/config/
	$(INSTALL_DATA) ./files/firewall.config $(1)/etc/config/firewall
	if [ ${CONFIG_PROJECT_NAME} == "DTO_NR8000_FST" ]; then \
		$(INSTALL_DATA) ./files/firewall_fst.config $(1)/etc/config/firewall; \
	fi
	$(INSTALL_DATA) ./files/childmodel.config $(1)/etc/config/childmodel
	$(INSTALL_DIR) $(1)/etc/
	$(INSTALL_BIN) ./files/urlfilter $(1)/etc/urlfilter
	$(INSTALL_BIN) ./files/ipfilter $(1)/etc/ipfilter
	$(INSTALL_BIN) ./files/macfilter $(1)/etc/macfilter
	$(INSTALL_BIN) ./files/firewall.user $(1)/etc/firewall.user
	$(INSTALL_BIN) ./files/inputwhitemacfilter $(1)/etc/inputwhitemacfilter
	$(INSTALL_BIN) ./files/forwardwhitemacfilter $(1)/etc/forwardwhitemacfilter
	$(INSTALL_BIN) ./files/forwardblackmacfilter $(1)/etc/forwardblackmacfilter
	$(INSTALL_BIN) ./files/forwardchildmodelfilter $(1)/etc/forwardchildmodelfilter
	$(INSTALL_BIN) ./files/inputblackmacfilter $(1)/etc/inputblackmacfilter
	$(INSTALL_BIN) ./files/guest-ap $(1)/etc/guest-ap
endef

$(eval $(call BuildPackage,firewall))
