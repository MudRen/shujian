// Room: /d/dzd/haitan2.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","��̲");
	set("long",@LONG
�������ǰ�ɫ��Ӳ��ɳ�������м����ű��ǵ���Ƭ�ͱ���ˮ��ˢ�ü���⻬����ʯ��
�����һЩ�����˳��ϰ��ĺ���,�����ɫ���ŵ�ɳ̲������һĨ���̡����СС�Ľ�ʯ��
��ɳ̲��,������Щ�ǳ��޴��ƺ����Բ���������һ��СϪ,�����߾��Ǵ��ǵ���ͷ�ˡ�
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"haitan3",
		"west" : __DIR__"haitan1",
		"north" : __DIR__"shulin1",
		"south" : __DIR__"matou",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south")
		return notify_fail("������ȥ����תת�ɡ�\n");
	
	return ::valid_leave(me, dir);
}

