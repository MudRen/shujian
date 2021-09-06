// whdmd-boook.c
// Created By Numa@SJ 2000

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"�廢���ŵ��ؼ�"NOR, ({ "wuhuduanmendao miji","miji","book" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�����廢���ŵ��Ĵ�ʼ��������ؼ�����ҳ���ƣ���������Ѿ���Զ��\n");
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
        add_action("do_po", ({"po","pour"}));
}

int do_du(string arg)
{
        object me = this_player();
        int neili, lev, lim;
        
        if(!id(arg)) return 0;

        if(me->query("gender") =="����")
                return notify_fail("����һ���¹٣���������������ѧ��\n");
        if(me->is_fighting())
                return notify_fail("���޷���ս����ר�������ж���֪��\n");
        if(me->is_busy()) 
                return notify_fail("��������æ���ء�\n");
        if(query_temp("mao18/book") != me->query("id"))
                return notify_fail("�������͵���ģ��ɲ���͵��Ŷ��\n");
        if(!me->query("mao18/pass"))
                return notify_fail("�������͵���ģ��ɲ���͵��Ŷ��\n");
        if(this_object()->query("clone_by_wizard") && !wizardp(me)) 
                return notify_fail("�������͵���ģ��ɲ���͵��Ŷ��\n");
        if(!me->query_skill("literate", 1)) 
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");        
        if(me->query("jing") < 20)
                return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
        lev = me->query_skill("wuhu-duanmendao", 1);
        lim = me->query_skill("blade", 1);
        if (lev <150)
                neili = 20;
        else
                neili = 20*(lev/100);
        if (me->query("neili") < neili) 
                return notify_fail("�������������޷�������ô������书��\n");
        if ( lev >= (me->query_skill("blade", 1) + 10))
                return notify_fail("������Ļ��������������޷��ٻ�ý�һ������ߡ�\n");

        if (!lev)
                write(HIG"\n�㿴�˿��ؼ�����Ƥ�Ϻ�Ȼд����"HIR"\n\n\t\t\t�廢���ŵ�\n\t\t\t\t\t����������\n\n"HIG"�㷭���ؼ������ַ��Ƶ���ҳ�ϼ��������������ӬͷС�֣�ÿҳ���в���������ͼ��\n"NOR);
        else if (lev > 149 && !me->query("mao18/pass2")) {
                        write(HIR"\n��о��Լ������廢���ŵ����в���δ����ȫ��͸��������Ҫ�Ҹ�ʦ��ָ��һ���ˡ�\n"NOR);
                        return 1;
        }
        else if (lev > 199 && !me->query("mao18/pass3")) {
                        write(HIR"\n�㽫�����ؼ��ж����ˣ�ǰ��������ʽ���趼������ͨ͸��ֻ�����һʽ�޷���͸��\n���������һҳ��Ȼд����"HIY"\n\n\t\t���мȳ������Ī�С�\n\t\t\t\t������Ե�ˡ�\n"NOR);
                        return 1;
        }
        else
                write("�������ж����廢���ŵ����ؼ����ƺ���Щ�ĵá�\n");
        me->receive_damage("jing", 20);
        me->receive_damage("neili", neili);
        me->improve_skill("wuhu-duanmendao", me->query_skill("literate", 1)/2 + me->query_skill("blade", 1)/2);

        if (!random(5))
                message("vision", me->name() + "����һ���ؼ����ڿ�����С�\n", environment(me), ({me}));
        return 1;
}

int do_po(string arg)
{
        object me = this_player();
        object ob;


        if (!arg)
                return notify_fail("��Ҫ��ʲô��\n");
        if (sscanf(arg,"from %s",arg) != 1)
                return notify_fail("��Ҫ��ʲô���ã�\n");
        if (!(ob = present(arg,me)))
                return notify_fail("������û������������\n");
        if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���أ�\n");
        if ((int)me->query_skill("wuhu-duanmendao",1) != 200)
                return notify_fail("��û����ˮ��ɶ��\n");
        if (me->query("mao18/pass3"))
                return notify_fail("������ƻ���ô�õ�һ���ؼ���\n");
        if (!ob->query("liquid"))
                return notify_fail("�ⲻ��������\n");
        if (ob->query("liquid/type") != "water")
                return notify_fail("�ⲻ����ˮ���õ��������ѿ���\n");
        if (ob->query("liquid/remaining") < 1)
                return notify_fail(ob->name() +"���Ѿ�ûˮ�ˡ�\n");
        message_vision("$N��"+ob->name()+NOR"�������е��ؼ�ֱ�ù�ȥ��������ʪ͸�ˡ�\n", me);
        ob->set("liquid/remaining",0);
        if (random(me->query_kar()) >= 15) {
                tell_object(me, HIY"��ͻȻ������ҳ������潥�����ֳ�����ӬͷС������\n����ϸ���꣬����ԭ��������廢���ŵ����һʽ����ϸ������������ʱ��ϲ����\n"NOR);
                me->set("mao18/pass3",1);
        }
        else
                write("�㲢û�������е��ؼ���ʲô�仯��\n");
        return 1;
}
