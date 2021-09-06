#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "ʮ�����ɢ" NOR, ({"shixiang ruanjinsan", "san"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "С��");
                set("no_get", 1);
                set("no_sell",1);
		set("no_drop", 1);
                set("no_steal",1);
        }
       setup();
}

void init()
{ 
	if (!userp(this_player())) return;
	add_action("do_fu","fu");
        add_action("do_action", ({"nick", "describe", "sj", "chat", "chat*", "rumor", "rumor*", "party", "party*",
		"new", "new*", "say", "to", "set",
		"mm", "emote", "shout", "alias", "quit", "post", "ask", "tell", "reply", "whisper", "team","group","irc",}));
	call_out("drop",600);
}

int do_fu(string arg)
{
        object me, ob;
	me=this_player();

        if( !arg || !objectp(ob = present(arg, environment(me))) 
        || !ob->is_character() || ob == me)
                return notify_fail("��Ȼ�������ܺóԣ�����С�ĵ�ɡ�\n");
        if (ob->query("id") != me->query_temp("zhao/targetid") ||
            ob->query("name") != me->query_temp("zhao/target"))
                return notify_fail("��������Ķ���\n");
        if (living(ob))
                return notify_fail("��̫��Ŀ�ŵ��ˡ�\n");
        
        message_vision(HIR"$N��һС��ʮ�����ɢȫ����$n�����ˣ�\n"NOR, me, ob);
        ob->apply_condition("ruanjin_poison",10);
        destruct(this_object());
        return 1;
}

int do_action(string arg)
{
//   if(!wizardp(this_player())) {
   write("�㻹��С���������ɡ�\n");
   return 1;
// }
}

void drop()
{
  object me = this_player();
  if (!me) return;
  message_vision(HIY"$Nһ���ڴ����ƺ�����ʲô������\n",me);
  me->delete_temp("zhao");
  destruct(this_object());
}
