// ɢ
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB "��ң��Цɢ" NOR, ({ "sanxiao san", "san" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ɫ��ɢ����һ���ͺ��о綾��\n");
                set("value", 1000);
                set("material", "paper");                
        }
        setup();
}

int init()
{
   add_action("do_tan", "tan");
}

int do_tan(string arg)
{
       object me, ob;
       int i;
       string msg;
       mapping fam;
       me = this_player(); 
       fam = me->query("family");  

        if (!fam || fam["family_name"] != "������")
        return notify_fail("�㲻�����޵��ӣ����Բ�������������ʹ�á�\n");
  
       if (!arg) return notify_fail("��Ҫ��˭���֣�\n");       
 
       ob = present(arg, environment(me));
       if (!ob) return notify_fail("�Ҳ���������\n");
       i = ob->query_skill("dodge", 1) + ob->query_skill("parry", 1);
       i = random(i/2) - 20;
       if( environment(me)->query("no_fight") )
                return notify_fail("�㲻�������ﶯ�֡�\n");
       if(me->is_busy())
                return notify_fail("����æ���ء�\n");
       if(me->query("neili") < 500)
                return notify_fail("������������������֡�\n");
       msg = BLU"\n$N������˻����ۣ�\n"NOR;       
       me->start_busy(2);
       me->add("neili", -100);
       me->add("jingli", -20);
       if(me->query_skill("force", 1) > i && random(ob->query("con")) < 20 &&
          me->query("max_neili") > (int)ob->query("neili")/2 ) {
          ob->apply_condition("sxs_poison", 3);
          }
       else {
          msg +=RED"$nƾ����������������Цɢ������Ӳ�������˻�ȥ��\n"NOR;
          msg +=RED"$N�о�����Цɢ�Ķ��Ѿ��������Լ����ڡ�"NOR;
          ob->add("jingli", -50);
          me->apply_condition("sxs_poison", 3);
          }              
       message_vision(msg, me, ob);
       destruct(this_object());
       return 1;
}
