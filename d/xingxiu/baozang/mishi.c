inherit ROOM;
#include <ansi.h>
#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"
#define QUESTDIR4 "quest/ѩɽ�ɺ�/�书/"
void create()
{
          set("short",HIC"����"NOR);
	  set("long",@LONG
��������һ�����ң���С�Ŀռ����ȷ�������������;��
LONG
           );

	  set("exits",([
              "out": __DIR__"shuku",
          ]));
    set("quest",1);
    set("baozang",1);
	  setup();
}
void init()
{
        add_action("do_search", "search"); 
        add_action("do_search", "xunzhao"); 
        add_action("do_search", "dig"); 
}
int valid_leave(object me, string dir)
{
      if((present("zhi tuan",me))||(present("tishi ka",me)))  return notify_fail(HIR"��Я���˲�����Я����ȥ����Ʒ���붪��֮���ٳ����뿪��\n"NOR);
       return ::valid_leave(me, dir);
}
int do_search(string arg)
{
  object me,obj;
  me = this_player();
  if (me->is_busy() || me->is_fighting())
		      return notify_fail("����æ���ģ�\n");
  message_vision(HIY"$N���ڵ��ϣ��Ĵ�Ѱ�ҡ�\n"NOR, me);
  if(!wizardp(me)) me->start_busy(1);
  if(me->query(QUESTDIR5+"shuku")>=4||random(2)||present("zhi tuan",me))
  {
       tell_room(environment(me), me->name() + "���˰��죬ֻŪ��һ���ࡣ\n", ({ me }));
       return notify_fail("�����˰��죬ʲôҲû�ҵ���\n");
  }
  me->add(QUESTDIR5+"shuku",1);
me->set_temp("no_bug",1);
  obj=new("/cmds/leitai/bwdh/obj/danwan");
  obj->set("owner",me->query("id"));
  if(me->query(QUESTDIR5+"shuku")==1) obj->set("secret_obj",1);
  obj->set("bonus","combat_exp");
  obj->move(me);
  message_vision(WHT"$N����һ��"+obj->name()+WHT"��\n"NOR, me);
  log_file("quest/FEIHU", sprintf("%s(%s)�ҵ����ҵı���%s������%d��\n"NOR, me->name(1),me->query("id"),obj->query("name"), me->query("combat_exp")) );
  me->start_busy(2);
   if(!me->query(QUESTDIR4+"lengquanshengong")&&((me->query(QUESTDIR5+"shuku")>=4 && me->query("registered")>=3)||(me->query(QUESTDIR5+"shuku")==3)))
{
	  message_vision(HIG"$N��"+obj->name()+HIG"��Ȼ����������һ��ֽ�š�\n"NOR, me);
	  tell_object(me,HIY"��չ��ֽ�ţ���ϸ���˿��ƺ����书�ؼ�֮��Ľ��ܡ�\n"NOR);
	  destruct(obj);
	  obj=unew("/d/xingxiu/baozang/obj/zhituan");
	  if(!clonep(obj)){
		  tell_room(environment(me), me->name() + "˳�ְ�ֽ�Ŷ��ˡ�\n", ({ me }));
		  log_file("quest/FEIHU", sprintf(HIR"%s(%s)���ֶ���ֽ�š�ע�������BUG��\n"NOR, me->name(1),me->query("id")) );
		  return notify_fail(HIY"�㿴�˿�ʲôҲû��������˳�ְ�ֽ�Ŷ��ˡ�\n"NOR);
	  }
	  obj->set("owner",me->query("id"));
	  obj->move(me);
	  me->add_busy(1);
	  log_file("quest/FEIHU", sprintf(HIR"%s(%s)�ҵ���Ȫ����ʾֽ�š�����%d��\n"NOR, me->name(1),me->query("id"),me->query("combat_exp")) );
	  return 1;
  }
  return 1;
}
