// /u/beyond/hangzhou/hubian.c ������
 
inherit ROOM;
void create()
{
        set("short","������");
        set("long", @LONG
��������ɽ��ˮ�㣬�̲�����������ɽɫ����ӳ��Ȥ�����ۺ������羵
���У������������续���Ρ�����֮�����������Թ����������ǳ����ޡ�
�����ġ��㡢�ᡢ�������������δ���ʫ�������ġ�ˮ�������緽�ã�ɽɫ
���������棬�������������ӣ���ױŨĨ�����ˡ�һʫ���������������ľ�
ɫ�������쾡�¡�
LONG
        );
	set("objects",([
		__DIR__"npc/you" : 2,
	]));
        set("exits", ([
		"southeast" : __DIR__"jingcisi",
		"north" : __DIR__"llwying",
		"west" : __DIR__"hubian2",
		"northwest" : __DIR__"hggyu",
	]));
	set("outdoors", "����");

	setup();
}
