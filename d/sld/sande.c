// sande.c
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
       "northwest"   :  __DIR__"sandn",
	"southwest" : __DIR__"dukou",
	"west" : __DIR__"treee1",
]));
	set("outdoors", "������");
        set("coor/x",500);
  set("coor/y",430);
   set("coor/z",0);
   setup();
}