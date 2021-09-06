// yingshe-boook.c
// by daidai
#include <ansi.h>
 
inherit ITEM;
 
void create()
 {
         set_name(HIC"ӥ���������ؼ��б�"NOR, ({ "yingshe miji","miji","book" }));
         set_weight(200);
         if( clonep() )
                 set_default_object(__FILE__);
         else {
                 set("unit", "��");
                 set("long","����һ����¼ӥ�����������ؼ������ǲ�ȱ��ȫ��һ�����޷�����\n");
                 set("value", 500000);
                 set("no_get","�������˵ı�����������õ��ߣ�\n");
                 set("no_drop","��ô���Ķ���������Ҷ���\n");
                 set("treasure",1);
                 set("unique",1);
                 set("material", "paper");
         } 
 }
 
 void init()
 {
         add_action("do_du", "read");
 }
 
 int do_du(string arg)
 {
         object me = this_player();
         int neili, lev;
         
         if(!id(arg)) return 0;
 
         if(me->is_fighting())
                 return notify_fail("���޷���ս����ר�������ж���֪��\n");
         if(me->is_busy()) 
                 return notify_fail("��������æ���ء�\n");
 
         if(!me->query("quest/��ɽ��/ӥ��������/pass"))
                 return notify_fail("�������͵�����ؼ����ɲ���͵��Ŷ��\n");
         if(this_object()->query("clone_by_wizard") && !wizardp(me)) 
                 return notify_fail("�������͵���ģ��ɲ���͵��Ŷ��\n"); 
         if(!me->query_skill("literate", 1)) 
                 return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");        
         if(me->query("jing") < 20)
                 return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
         lev = me->query_skill("yingshe-shengsibo", 1);
         if (lev >150)
                 return notify_fail("���Ѿ����ܴ��Ȿ����õ��κ�ָ���ˡ�\n");
             neili = 20+random(20);
              if (me->query("neili") < neili) 
                 return notify_fail("�������������޷�������ô������书��\n");
          if (!lev)
                 write(HIC"\n�㿴�˿��ؼ�����Ƥ�Ϻ�Ȼд����"HIW"\n\n\t\t\tӥ��������\n\n"HIY"�㷭���ؼ������ֲ��Ƶ���ҳ�ϼ����Ų���������ͼ��ھ������Ǻ�����Щ��ȱ��\n"NOR);
         write("���ж���ӥ�����������ؼ��б��������Լ�������Ҫ�����ƺ���Щ�ĵá�\n");
         me->receive_damage("jing", 20);
         me->receive_damage("neili", neili);
         me->improve_skill("yingshe-shengsibo", me->query_skill("literate", 1) );
         me->improve_skill("hand", random(me->query_skill("literate", 1)) );
         me->improve_skill("claw", random(me->query_skill("literate", 1)) );
 
         if (!random(5))
                 message("vision", me->name() + "����һ����ȱ���ؼ�һ���ж�һ�����в��ϱȻ��š�\n", environment(me), ({me}));
         return 1;
 } 
 
 


