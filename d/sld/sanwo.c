// sandn.c
// ɳ̲��

inherit ROOM;
void create()
{
	set("short", "ɳ̲");
	set("long",@long
�����ض��Ǳ���ˮ��ˢ�����Ļ�ɫ��ϸɳ������������һ�������ࡢʪ
�����ĸо����������Կ�����Сз֮�ණ����ϸɳ��������ȥ����ʱ�����Կ�
�����������������Ϻ�������������и����֡�
long);
	set("exits",([
       "southeast"   :  __DIR__"sande",
	"southwest" : __DIR__"sandw",
	"south" : __DIR__"treen1",
	]));
	set("outdoors", "������");
        setup();
}
