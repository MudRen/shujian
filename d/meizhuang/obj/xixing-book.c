// yingshe-boook.c
// by daidai
#include <ansi.h>
 
inherit ITEM;
 
void create()
 {
         set_name(HIR"���Ǵ��ر�"NOR, ({ "xixing miji","miji","book" }));
         set_weight(200);
         if( clonep() )
                 set_default_object(__FILE__);
         else {
                 set("unit", "��");
                 set("long","����һ����¼���Ǵ󷨵��ؼ����Ǵ�÷ׯ���������������ģ�һ�����޷�����\n");
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
 
         if(!me->query("quest/xxdf/pass"))
                 return notify_fail("�������͵�����ؼ����ɲ���͵��Ŷ��\n");
         if(this_object()->query("clone_by_wizard") && !wizardp(me)) 
                 return notify_fail("�������͵���ģ��ɲ���͵��Ŷ��\n"); 
         if(!me->query_skill("literate", 1)) 
                 return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");        
         if(me->query("jing") < 20)
                 return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
         lev = me->query_skill("xixing-dafa", 1);
         if (lev >200)
                 return notify_fail("���Ѿ����ܴ��Ȿ����õ��κ�ָ���ˡ�\n");
             neili = 20+random(20);
              if (me->query("neili") < neili) 
                 return notify_fail("�������������޷�������ô������书��\n");
          if (!lev)
                 write(HIR"\n�㿴�˿��ؼ�����Ƥ�Ϻ�Ȼд����"HIR"\n\n\t\t\t���Ǵ�\n\n"HIY"�㷭���ؼ��������Ȿ��Ȼ������������Ǵ�֮�ڹ���Ҫ��\n"NOR);
         write("���ж������Ǵ󷨡��ؼ��ر��������Լ�������Ҫ�����ƺ���Щ�ĵá�\n");
         me->receive_damage("jing", 30);
         me->receive_damage("neili", neili);
         me->improve_skill("xixing-dafa", me->query_skill("literate", 1) );
 
         if (!random(5))
                 message("vision", me->name() + "����һ���ؼ���������ж��š�\n", environment(me), ({me}));
         return 1;
 } 
 
 


