// Room: /d/dzd/haitan1.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","��̲");
	set("long",@LONG
�������ǰ�ɫ��Ӳ��ɳ�������м����ű��ǵ���Ƭ�ͱ���ˮ��ˢ�ü���⻬����ʯ��
�����һЩ�����˳��ϰ��ĺ���,�����ɫ���ŵ�ɳ̲������һĨ���̡����СС�Ľ�ʯ��
��ɳ̲��,������Щ�ǳ��޴��ƺ����Բ���������һƬ�ݵ�,���Ͼ��Ǵ��ǵ���ͷ��
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"haitan2",
		"north" : __DIR__"xiliu1",
		"northwest" : __DIR__"caodi1",
		"southeast" : __DIR__"matou",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southeast")
		return notify_fail("������ȥ����תת�ɡ�\n");
	
	return ::valid_leave(me, dir);
}

