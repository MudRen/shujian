// Room: /d/shaolin/chufang1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ƣ��������ڣ���ζ�˱Ƕ�������ǽ��һ�����ɳ�����̨��֧��
ʮ���ڴ��������һ�ڷ����Ϸ������˴��������ն��£��ֳ�ľ���ڽ���
�������շ���ɮ���⣬��λ��ͷ��æ��������н������¯�����ܡ�һλ��
��ɮ�������شߴ��š�
LONG
	);

	set("exits", ([
		"south" : __DIR__"chufang2",
                "west" : __DIR__"fanting1",
	]));

	set("objects",([
		__DIR__"npc/shaofan-seng" : 1,
                __DIR__"npc/hg-toutuo" : 1,
	]));
	set("coor/x",90);
  set("coor/y",240);
   set("coor/z",110);
   setup();
}



