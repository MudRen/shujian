// Room: /d/dzd/haitan3.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","��̲");
	set("long",@LONG
�������ǰ�ɫ��Ӳ��ɳ�������м����ű��ǵ���Ƭ�ͱ���ˮ��ˢ�ü���⻬����ʯ��
�����һЩ�����˳��ϰ��ĺ���,�����ɫ���ŵ�ɳ̲������һĨ���̡����СС�Ľ�ʯ��
��ɳ̲��,������Щ�ǳ��޴��ƺ����Բ���������һƬ���֣����Ͼ��Ǵ��ǵ���ͷ��
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"west" : __DIR__"haitan2",
		"north" : __DIR__"shulin2",
		"northeast" : __DIR__"shulin3",
		"southwest" : __DIR__"matou",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southwest")
		return notify_fail("������ȥ����תת�ɡ�\n");
	
	return ::valid_leave(me, dir);
}
