
inherit ROOM;

void create()
{
	set("short", "��Ʒ��");
	set("long", @LONG
�������������ڵ���Ʒ��������ѵ������ģ��㿴�˿���������
һ���ŵĴ�ľ�ܣ����Ϸ��������Ʒ��ȴ��ճ�ҳ�����������ʱ����
������ɨ�������ȥ�Ǵȱ�Ժ��
LONG);
	set("exits", ([ 
           "south" : __DIR__"cby",
        ]));
	set("coor/x",-340);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}
void init()
{
      // add_action("do_clean", ({"clean","��ɨ"}))
}

int do_clean(string arg)
{
     object me=this_player();

     if(arg != "ľ ��" ){
          message_vision("$N������İ���Ʒ����ɨ��һ�顣\n", me);
          return 1;
          }
     if(random(100) < 5){               
           message_vision("$N������Ĵ�ɨ����Ʒ���е�ľ���϶ѷŵĸ�ʽ��Ʒ��
һ���ƾɵ���ͻȻ��ľ�ܷ��е���������\n", me);
           new("/clone/medicine/m-book4")->move(me);
           }
     else message_vision("$N������İ���Ʒ����ɨ��һ�顣\n", me);
     return 1;
}
