// Room: /d/shaolin/chufang2.c
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
		"north" : __DIR__"chufang1",
                "west" : __DIR__"fanting3",
                "south" : __DIR__"xiaolu-1",
	]));

	set("objects",([
		__DIR__"npc/shaofan-seng" : 1,
                __DIR__"npc/hg-toutuo" : 1,
	]));
	set("coor/x",90);
  set("coor/y",230);
   set("coor/z",110);
   setup();
}



