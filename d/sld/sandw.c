// sandw.c
// ɳ̲��

inherit ROOM;
void create()
{
	set("short", "ɳ̲");
	set("long",@long
�����ض��Ǳ���ˮ��ˢ�����Ļ�ɫ��ϸɳ������������һ�������ࡢʪ
�����ĸо����������Կ�����Сз֮�ණ����ϸɳ��������ȥ����ʱ�����Կ�
�����������������Ϻ�����������Ͼ��Ƕɿ��ˣ��������и����֡�
long);
	set("exits",([
       "northeast"   :  __DIR__"sandn",
	"southeast" : __DIR__"dukou",
	"east" : __DIR__"treew1",
]));
	set("outdoors", "������");
        set("coor/x",470);
  set("coor/y",400);
   set("coor/z",0);
   setup();
}