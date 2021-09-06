// jiuyang-zhenjing.c
// Modified by jpei
// Modify By River@SJ 99.06
// By Spiderii@ty �����츳
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"�����澭"NOR, ({"jiuyang zhenjing", "jiuyang", "zhenjing", "book"}));
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���Ĳᱡ���ľ��顣\n");
                set("value", 8000);
                set("unique", 1);
                set("material", "paper");
                set("no_drop", "��ô���������ؼ�����ɲ������ⶪ����\n");
                set("no_get", "�������������˵ı�������˯����Ҫ����ͷ�棬���޷���ȡ��\n");
                set("treasure", 1);
        }
}

void init()
{
        add_action("do_du", "read");
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        int jylevel, neili_lost, lv;

        if(!id(arg)) return 0;

        if(me->query("gender") =="����")
                return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");
                
        if(me->is_busy()) 
                return notify_fail("��������æ���ء�\n");
                
        if(query_temp("jiuyang") != me->query("id"))
                return notify_fail("�������͵���ģ��ɲ���͵��Ŷ��\n");
                
        if(me->is_fighting())
                return notify_fail("���޷���ս����ר�������ж���֪��\n");
                
        if(where->query("outdoors") != "���ش��" )
                return notify_fail("��ֻ�������ش���в��ܾ��������ж������澭��\n");
                
        if(!me->query("jiuyang/baiyuan"))
                return notify_fail("�������͵���ģ��ɲ���͵��Ŷ��\n");
                
        if(!me->query_skill("literate", 1)) 
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");        
                
        if(me->query("jing") < 25)
                return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                
        if(me->query_skill("force",1) < 100) 
                return notify_fail("����ڹ�����û�д�ã��������������񹦡�\n");
                
        if(me->query_int() < 40)
                return notify_fail("����������Բ������޷���ϰ�����񹦡�\n");

        if(this_object()->query("clone_by_wizard") && !wizardp(me)) 
                return notify_fail("�������͵���ģ��ɲ���͵��Ŷ��\n");

        jylevel = me->query_skill("jiuyang-shengong", 1);
        if (jylevel < 30)
                neili_lost = jylevel / 2;
        else if (jylevel < 70)
                neili_lost = jylevel* 2 / 3;
        else if (jylevel < 140)
                neili_lost = jylevel* 3 / 4;
        else
                neili_lost = jylevel;
        if( neili_lost > 150) neili_lost = 150;
        if ( jylevel >= (me->query_skill("force", 1) + 30))
                return notify_fail("��������ڹ��Ļ����������ٻ�ø���һ�����ߡ�\n");
        if ( jylevel >= (me->query_skill("shenghuo-shengong", 1)+ 10) && jylevel < 220)
                return notify_fail("�������ʥ���񹦻�򲻹������ܻ�ø���һ�����ߡ�\n");
        if (me->query("neili") < neili_lost) 
                return notify_fail("�������������޷�������ô������书��\n");
        if (me->query("combat_exp") < jylevel * jylevel * jylevel / 10) 
                return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
        if (jylevel >= 140 && me->query("neili") < jylevel * 3 )
                return notify_fail("�����һ�����ϵ����ݹ�����£��⿿�ж����������������޷��ٻ�ý����ġ�\n");
        me->receive_damage("jing", 20);
        me->receive_damage("neili", neili_lost);
        if (!jylevel) {
                write(HIW"\n�㷭����һ�ᾭ�飬�������澡���������������ģ���ÿһ��֮��ȴ��ӬͷС��д�����й����֡�\n"NOR);
                write(HIW"�㶨һ���񣬴�ͷϸ�������������������ǹ������������ľ��ϡ�\n"NOR);
                write(HIW"�㿪ʼ�ж���һ�ᣬ���潲�������������š�\n\n"NOR);
        }
        if (jylevel >= 140)
                write("�㰴��������������һ���ٶ������ж��������澭�����һ�ᣬ����е��ĵá�\n");
        else
                write("���ж��������澭���������ĵá�\n");
        me->improve_skill("jiuyang-shengong", me->query_skill("literate", 1));
        if (!random(9)) message("vision", me->name() + "����һ�������������С�\n", environment(me), ({me}));
        if (me->query_skill("jiuyang-shengong", 1) > jylevel) {
                if (jylevel == 29) {
                        write(HIW"\n������˵�һ�ᣬ������������������Ż���������ѧ��\n"NOR);
                        write(HIW"�㿪ʼ�ж��ڶ��ᣬ���潲�������������š�\n\n"NOR);
                }
                else if (jylevel == 69) {
                        write(HIW"\n������˵ڶ��ᣬ��Ȼ���������������������Щ�Ѷȣ����ǲ�û��̫��µĵط���\n"NOR);
                        write(HIW"�㿪ʼ�ж������ᣬ���潲������������Ҫ��\n\n"NOR);
                }
                else if (jylevel == 139) {
                        write(HIW"\n������˵����ᣬ�����������������Ҫ��Ϊ�������˺ô�ľ�����ȫ����ˡ�\n"NOR);
                        write(HIW"�㿪ʼ�ж����Ĳᣬ���潲�����Ѿ���ʮ�ּ�����ڹ���Ҫ���������൱���ѡ�\n\n"NOR);
                }
                else if (jylevel == 219) {
                        write(HIW"\n�����ڶ����˵��Ĳᣬ�ҹ����һҳ֮���������ǻ�ϲ����΢΢�е���㯡�\n"NOR);
                        write(HIW"��ָ����������Ĺ����ҴҶ���������ʼ����Բ����\n\n"NOR);
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        lv = me->query("max_pot")-100;
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�������˾����񹦵ľ������ڡ�\n"NOR);
            me->set_skill("jiuyang-shengong",lv);
            }

                }
        }
        if( !me->query("jiuyang/read")){
		me->set("jiuyang/read", 1);
		log_file("quest/jiuyang",sprintf("%8s%-10s�ɹ��õ�����ʼ�ж������񹦣���ʱ�ȼ��ǣ�%s��\n",
			me->name(1),"("+capitalize(me->query("id"))+")", chinese_number(jylevel)), me);
        }
        return 1;
}
