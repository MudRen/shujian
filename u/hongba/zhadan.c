inherit ITEM;
#include <ansi.h>
void create()
{
set_name( HIY"����ը��"NOR, ({ "zhadan"}) );
set("long", "����һ������ʮ���ը����ר������ը(zha)�����е���ʦ���Ρ�\n");
set_weight(1000);
if( clonep() )
                   set_default_object(__FILE__);
else {
                     set("unit", "��");
                     set("value", 0);
                     }
                     setup();
}

void init()
{
 add_action("do_zha","zha");
}

int do_zha(string arg)
{
 object ob,me=this_player();
 if(!arg) return notify_fail("����ը˭��\n");
 if(!ob=find_player(arg)) return notify_fail("����ը˭��\n");
 if( !wizardp(ob) ) return notify_fail("��ֻ��ը��ʦŶ��\n");
 if( !ob->query("env/invisibility") ) return notify_fail("�ѵ��㿴�����Ǹ���ʦ��\n");
 if( me->query_temp("zhadan") ) return 1;
message_vision("$Nȡ��һ������ը����������һ�ף�����ը�������۾��Ƶģ���Զ����ȥ...\n��һ�����Զ������һ�����졣\n",  me );
message("vision", HIR"��Ȼһ������ը����Х����"+ob->name()+"����������,���һ���죬"+ob->name()+"��ը����ԭ�Ρ�\n"NOR,  environment(ob), ({ ob }) );

tell_object(ob,"��Ȼһ������ը��ײ�������ϣ���ը�ˣ��Ƶ����ֳ���ԭ�Ρ�\nԭ����"+me->name()+"���㶪����ը��:->��\n");
message("channel:wiz", HIR"��ҥ�ԡ���"+ob->query("name")+"��ը����ԭ�Ρ�\n"NOR, users());
message("channel:chat", HIR"��ҥ�ԡ���"+ob->query("name")+"˫�ֱ�ͷ��ʹ�����飬����񺰣�����װ�ƣ��ұ���������\n"NOR, users());
 me->set_temp("zhadan",1);
 ob->set("env/invisibility",0);
 destruct(this_object());
 return 1;
}

