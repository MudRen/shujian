// Room: /d/shaolin/gulou4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "��¥�Ĳ�");
	set("long", @LONG
������¥�ݴ��ֻ����һ�����£�ǽ��Ҳ�Ա���Щ������Խ����������
�ߵ����䳡���޺��ã�������������Ŀ������ɮ�����㼯�����䳡��ϰ�䣬
ߺ����һ���󴫽����ġ����ߵ������ɽ�ŵ�Ҳ��¶ȫò��
LONG
	);

	set("exits", ([
		"up" : __DIR__"gulou5",
		"down" : __DIR__"gulou3",
	]));

	set("coor/x",20);
  set("coor/y",230);
   set("coor/z",150);
   setup();
}



