//tangfeng@SJ 8/2004

inherit ROOM;
#include <ansi.h>
#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"

void create()
{
            set("short",HIW"����"NOR);
            set("long",@LONG
�����Ǳ���ͼ��־����̳���޴�Ĺ㳡�������󵱳���ν��졣�м����
��һ���޴����̳�������Ǽ������ã�������Ϊ����ľ�Զ���Ѿ���Щ���ݡ�
����Ӱ����������ơ�
LONG
       );
        set("exits", ([
                "east" : __DIR__"midong1",
                "south" : __DIR__"midong2",
                "west" : __DIR__"midong3",
                "north" : __DIR__"midong4",
        ]));
            set("valid_startroom", 1);
            set("quest", 1);
            set("no_fight", 1);
            set("no_get", 1);
            set("baozang",1);
            setup();
}

void init()
{
int i;
  object me,ob,*obj;
  ob = this_object();
  me = this_player();
  obj = deep_inventory(me);
   i = sizeof(obj);
  while (i--)
  if (obj[i]->is_character())
      me->set_temp("out",1);
  if (me->query_temp("out")||!me->query(QUESTDIR5+"start")||!me->query_temp(QUESTDIR5+"search_ok")
        ||!me->query_temp(QUESTDIR5+"map_where")||me->query_condition("killer"))
  {
     me->delete_temp("out");
     me->delete_temp(QUESTDIR5+"search_ok");
     me->delete_temp(QUESTDIR5+"search");
          message_vision(YEL"ͻȻ$N����һ���������������ﲻ��ӭ$N����\n"NOR,me);
    if(!wizardp(me)) 
      {
             me->move("/d/xiangyang/damen");  
           tell_object(me,YEL"��̧��һ�������ﾹȻ����ݴ��ţ��ղŵ�һ������һ����á�\n"NOR); 
    }
    else 
     {
          if(random(2)) message_vision(YEL"$N�ƺ���Щ���ߣ��ſ��������û��������˭����������ʦ"+me->query("name")+"��\n\n"NOR,me);
          else message_vision(YEL"$N����һ����ͻȻ����ɢ��������е����ƣ���ͷ����ԼԼ�Գ��������֣�"NOR+HIY+me->query("name")+NOR+YEL"��\n\n"NOR,me);
          message_vision(YEL"�ղ���е���������Ҳ�ƺ���Ϊ$N������ή�˻�ȥ��$N���ɵص����һЦ��\n"NOR,me);
          message_vision(YEL"ͻȻһ��������ɳ�һֻЬ�ӣ����һ���ҵ�$Nͷ�ϣ�����һ������������������˭��TMD��\n"NOR ,me);
          me->unconcious();
    }
     return;   
  }
   if(ob->query("busy")&&ob->query("busy")!=me->query("id"))
  {
     tell_object(me,YEL"ͻȻ������һ�����������������Ѿ���������һ���ˣ���\n"NOR); 
     me->move("/d/xiangyang/damen");  
     me->delete_temp(QUESTDIR5+"search_ok");
      me->delete_temp(QUESTDIR5+"search");
     tell_object(me,YEL"��̧��һ�������ﾹȻ����ݴ��ţ��ղŵ�һ������һ����á�\n"NOR); 
     return;   
   }
  ob->set("exits/up",me->query_temp(QUESTDIR5+"map_where"));
  ob->set("busy",me->query("id"));//��������޷�����
  remove_call_out("check");
  call_out("check",1,me);
}
int valid_leave(object me, string dir)
{
        if ( dir == "up" && userp(me) && me->query(QUESTDIR5+"start")) this_object()->delete("busy");
        return ::valid_leave(me,dir);
}
void check(object me)
{
	object obj;
	remove_call_out("check");
	if(!me||!living(me) || !environment(me)->query("baozang"))
	{
		this_object()->delete("exits/up");
		this_object()->delete("busy");
		return;
	}
        if((obj=present("baozang tu",me))) 
        {
                            tell_object(me,YEL"��˳�ֶ���"+obj->query("name")+YEL"��\n"NOR); 
              message_vision(HIC"$N����һ��"+obj->query("name")+HIC"��\n" NOR,me);
              message_vision(obj->query("name")+HIC"���ʱһ������Ȼʧȥ����Ӱ��\n" NOR,me);
                    destruct(obj);
       }
  call_out("check",1,me);
}
