inherit ROOM;

void create()
{
        set("short", "���㾶");
        set("long",@long
������Ϊ���㾶���ֳơ�һ����������Ϫ�������������ʩ��ɽ֮�ؾ�
֮ˮ����Ҳ��Խ����ʱ�����Я��ʩ����С�۳���֮����
long);
set("outdoors", "suzhou");
set("exits",([
"northwest" : __DIR__"shuiwa",
"northeast" : __DIR__"shuiwa1",
]));
set("coor/x",150);
  set("coor/y",-310);
   set("coor/z",10);
   setup();
}
