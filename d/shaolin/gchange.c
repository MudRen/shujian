// Room: /d/shaolin/gchange.c
// Date: CSWORD 96/02/28

inherit ROOM;

void create()
{
	set("short", "��ǰ�㳡");
	set("long", @LONG
������������ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊƽ̹��������
����Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г��˳������㳡��Χ��������
�������֣��Ľ��ϸ����˼���ʯ�����ּ�����Ϊģ������ǰ����������վ�ż�
��ɮ�ˡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"guangchang",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		CLASS_D("shaolin") + "/qing-wu" : 1,
	]));
	setup();

}
