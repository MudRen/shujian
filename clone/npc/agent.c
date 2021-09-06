// agent.c ������
// Creat By Looklove 2000/2/24
// A agent for sell Good weapon, armor, etc ...


/* ���壺v ��Ʒ�����۸�(value)
        v2 ��Ʒ���� ( ��Ӷ�� )
        v3 �м�� (��ȥ����Ӷ���)
        vt ��ʱ�۸� (ֻ������㣩
        vs ������
        b  ���
        t  �ּۻ��ۼ���
        pur ��Ҵ���
*/

#include <ansi.h>
inherit NPC;

string ask_money();
string ask_pay();
string ask_back();

void create()
{
        set_name("����ͷ", ({ "bao laotou", "bao", "laotou" }));
        set("title",HIC"�����м�"NOR);
        set("gender", "����");
        set("long","������ɫ��������̬������С�����������ŵ�˯���ž���\n");

        set_max_encumbrance(100000000);
        set("age", 55);
        set("pur",2);

        set("no_get_from", 1);
        set("no_clean_up", 0);
        set("no_bark", 1);

        set("shen_type", 0);
        set("max_qi",800000);
        set("eff_qi",800000);
        set("qi",800000);
        set("max_jing",800000);
        set("eff_jing",800000);
        set("jing",800000);
        set("max_jingli",800000);
        set("eff_jingli",800000);
        set("jingli",800000);
        set_skill("unarmed", 60);
        set_skill("dodge", 800);
        set_skill("trade", 500);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

         set("combat_exp", 5000);
        set("attitude", "friendly");
        set("startroom","/d/city/bqp");

        set("unique", 1);
        set("chat_chance", 20);
        set("chat_msg", ({
                "����ͷ��������: �졫�����ˡ��𡫴����ˡ�\n",
                "����ͷ������ش��˸���Ƿ��\n",
                "����ͷС������˵��: ���ϵ����ѣ�Ҫ��Ҫ�������λ���\n",
                (: random_move :)
        }) );

        set("inquiry", ([
                "agent": "��ʲô���������ȹ���(value)��ͬ���Ǯ�Ͱ���������ȻҪ��ȡһ�ɵ�Ӷ��\n",
                "ת��": "ת��ʲô�������ȹ���(value)��ͬ��Ͱ���������Ȼ��Ҫ��ȡһ�ɵ�Ӷ��\n",
                "����": "��ʲô�������Ұ�������ֻ��ȡһ�ɵ�Ӷ��\n",
                 "����": "������ʲô��������Ҫ�������ҹ��¼�(value)��\n",
                "money": (: ask_money :),
                "����": (: ask_pay :),
                "pay": (: ask_pay :),
                "goods" : (:ask_back:),
                "����" : (:ask_back:),
                "name" : "����ԭ���ձ��ģ�ר�Ű��˴���(agent)�ɻ��������Ÿ�������ա�\n",
                "rumors" : "��˵Ϊ�˹���Ͷ�ʣ�����������Ҫ�µ��ˡ�\n",
                "Ӷ��" : "Ӷ���������Ǯ�����Ժ���׬���Ǯ���������ң���ʱ���Ҹ�������ô׬��\n",
                "����" : "�����������ģ��е��Ǳ�������ͭ����Ҳ�������㿴(kan)һ�¾�֪���ˡ�\n",
                "����" : "��֪���Ҷ���ʲô��������(list)һ�¾�֪����\n",
                "gold" : "����Ұ�������ʲô�������������ѣ�Ʃ�硰���⡱ʲô�ġ�\n",
                "Ǯ" : "����Ұ�������ʲô�������������ѣ�Ʃ�硰���⡱ʲô�ġ�\n",
                "����" : "������û�գ���æ����,���������ȹ�����(value)��\n",
                "����" : "��֪���Ҷ���ʲô������������list ����list <��ƷID> ����ѯ��\n",
                ]) );

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        ::init();
       add_action("do_value","value");
       add_action("do_value","gujia");
       add_action("do_agent","agent");
       add_action("do_buy","buy");
       add_action("do_list","list");
       add_action("do_list","kan");
}

int do_value(string arg) //���۲���
{
        object ob, me;
        int v, v2, pur;

        if( !arg )
                return notify_fail("��ʽ�� value <��Ʒ>\n");

        me = this_player();
        pur = (int)me->query("pur");

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");

        if(!wizardp(me)&&!ob->query("imbued" ))       //Ŀǰֻ������������ı���,�����Ժ����ӿ��Դ���������Ʒ��
                return notify_fail("Ŀǰֻ������������ı�����\n");

        if( me->is_busy() || me->is_fighting() )
                return notify_fail("����æ����˵�ɡ�\n");

        if (query_temp("busy")&&!wizardp(me))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

        if( ob->query("equipped"))
                return notify_fail("Ҫ���������ȷ��°���\n");

        if( ob->query("broken"))
                return notify_fail("�Ҳ������𻵵�������\n");

        if( ob->query("valued")){       // "valued" ��Ʒ�ѹ��۱�ǡ�
                v2 = (int)ob->query("valued");
                message_vision(CYN"$n���˿�"+ob->name()+CYN"˵�����������Լ����"+MONEY_D->money_str(v2)+"����\n"NOR, me, this_object());
                set_temp("busy", 1);
                call_out("delete_temp", 1, "busy");
                return 1;
        }

        v = (int)ob->query("value");    // ԭʼ�۸�
        v2 = v*5 + random(v*5);          // v2 �ѹ���
        ob->set("valued",v2);           // ��Ʒ���۱��
        message_vision(CYN"$N����$n��æ����"+ob->name()+CYN"��\n"NOR, me, this_object());
        message_vision(CYN"$n���˿�"+ob->name()+CYN"˵�����������Լ����"+MONEY_D->money_str(v2)+"���ҡ���\n"NOR, me, this_object());
        return 1;
}

int do_buy(string arg)  //��������
{
        object me, ob;
        int b, v2, vs, t, pur, improve;

        me = this_player();
        pur = (int)me->query("pur");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");

        if (query_temp("busy")&&!wizardp(me))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

        if (base_name(environment()) != query("startroom"))
                return notify_fail("�⡣����������ǳ�������ģ����´����ɡ�\n");

        if (!arg) return notify_fail("������ʲô��\n");

        if( !objectp(ob = present(arg, this_object())) )
                return notify_fail("������Ķ���������û�С�\n");


        v2 = ob->query("valued");               //��ѯ��Ʒ���۱��
        b = me->query("balance");               //��ѯ��Ҵ��

        t = (int)me->query_skill("trade",1);
        vs = v2 + pur + random(pur) - t/4;      /* vs �����۸� ׼�������ֹ��ּۻ���ʱ����,Ŀǰֱ��ʹ��v2 */

        if( v2 > b) return notify_fail("���Ǯׯ���Ѿ�û����ô��Ǯ�ˡ�\n");

        ob->delete("valued");                   //��Ʒ������
        ob->delete("agentby");
        ob->delete("no_get");
        me->add("balance",-v2);                 //���׶�Ӵ���п۳�

        ob->set("user_weapon", geteuid(me));
        ob->move(me);
        message_vision("$N��"+MONEY_D->money_str(v2)+"�ļ۸��$n����������һ" + ob->query("unit") +
                ob->name() + "��\n", me, this_object());

        improve = 40 - pur;
        me->improve_skill("trade", improve / 2 + random(improve));

        this_object()->add("balance",v2/10);    //��¼Ӷ������
        set_temp("busy", 1);
        call_out("delete_temp", 1, "busy");
        return 1;
}

int do_agent(string arg)        // ����������Ч
{
        object ob, me;
        int v2, v3, vt;

        if( !arg )
                return notify_fail("��ʽ�� agent <��Ʒ>\n");

        me = this_player();

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");

        if(!ob->query("valued"))                //��Ҫ�ȹ���
                return notify_fail("����������û�й��ۣ������ȹ���(value)�ɡ�\n");

        if(!ob->query("imbued" ))
                return notify_fail("Ŀǰֻ������������ı�����\n");

        if( ob->query("saved") )
        	return notify_fail("���������˽����Ʒ���������ȷ�����������\n");

        if( me->is_busy() || me->is_fighting() )
                return notify_fail("����æ����˵�ɡ�\n");

        if (me->query("agent")&&!wizardp(me))           //Ŀǰ��ʱֻ�ܴ���һ����Ʒ,׼���Ժ󿪷Ÿ��ࡣ
                return notify_fail("���Ѿ��������һ�������ˡ�\n");

        if( ob->query("equipped"))
                return notify_fail("Ҫ���������ȷ��°���\n");

        v2 = ob->query("valued");
        v3 = v2*9/10;
        vt = v2 - v3;

        if (!me->query("agent")) me->set("agent",v3);   //�����������v3��ǣ�v3 = v2 * 90% ���û��,add ��
        else me->add("agent",v3);                       //addΪ���Ŵ���������Ʒ׼��,��ȻΪ����bug,����set��

        ob->move(this_object());
        ob->set("agentby",me->query("id"));             //��Ʒԭ���˱��
        ob->set("byname",me->query("name"));
        ob->set("no_get",1);

        if (!ob->query("no_steal")) ob->set("no_steal",1); //��Ʒ��ֹ��ȡ

        message_vision(CYN"$N������$n��"+MONEY_D->money_str(v2)+"�ļ۸����"+ob->name()+CYN"��\n"NOR, me, this_object());
        message_vision("$N������$n��"+ob->name()+"����ͷ����Ӷ����"+MONEY_D->money_str(vt)+"��\n", this_object(), me);

        //������Ϣ
        if(ob->query("value")>1000000){
        message("system", HIC "���������š�������Ҫת��һ"+ ob->query("unit") + ob->name()+"��"HIC"�������ɰ���ͷ������\n" NOR,users());
        }
        return 1;
}

int do_list(string arg)           //������Ʒ�б� ���Ų�ѯ��Ʒ��ϸ�������ܡ�
{
        int i, goods;
        object *inv, ob;

        inv = all_inventory(this_object());     //����������������Ʒ��
        goods = sizeof(inv);

        if (goods<2 ) return notify_fail("Ŀǰû��ʲô�������Ķ�����\n");

        if (!arg){
        write("Ŀǰ����ͷ����������Ʒ��\n");

        foreach (ob in inv)
                if(ob->query("valued"))
                write(sprintf("%-30s ���ۣ�%s\n", ob->short(),
                MONEY_D->money_str(ob->query("valued"))));
                return 1;
        }

        if( !objectp(ob = present(arg, this_object())) )
                return notify_fail("���뿴ʲô����������list <��ƷID> ��ʽ��\n");

        if(ob->query("valued")){
                for (i = 0; i < sizeof(inv); i++){
                if( arg == (string)inv[i]->query("id"))
                write(sprintf("��Ʒ��    %s\nί���ˣ�  %s (%s)\n������    %s\nת�üۣ�  %s��\n \n",inv[i]->name(),inv[i]->query("byname"),inv[i]->query("agentby"),inv[i]->long(),MONEY_D->money_str(inv[i]->query("valued"))));
                }
                write("����������Ҫ�鿴��Ʒ��׼ȷID��\n");
                return 1;
        }
        write("����û��������Ʒ��\n");
        return 1;

}

string ask_pay()        //��ȡӶ����ȡ�����
{
        object me, *inv;
        int pay, i;
        // pay ʵ�ʵ��� v3, ��Ӷ�𲿷�ʵ�ʽ�

        me = this_player();
        pay = (int)me->query("agent");  //��ѯ��ұ��

        inv = all_inventory(this_object());

        if( !pay ) return "����Ҫʲô��";

        //��ѯ��Ʒ�Ƿ��۳���
        for (i = 0; i < sizeof(inv); i++)
        if((string)me->query("id") == (string)inv[i]->query("agentby")) return "�����һ�û���������Ժ���˵�ɡ�";

        message_vision(CYN"$N���ͷ��$n���������Ѿ����ˣ���ȥӶ���Ұ������"+MONEY_D->money_str(pay)+"��Ǯׯ���Լ�ȥȡ�ɡ�\n"NOR, this_object(), me);
        me->add("balance",pay);         //���ת����Ҵ�
        me->delete("agent");            //�����ұ�ǡ�
        return "�´�������£��ǵ������ҡ�";
}

string ask_money()      //���Բ��֣�Ӷ���ۼơ�
{
        int n;
        n = this_object()->query("balance");
        if( n <1 ) return "�ҽ��컹û�п��š�";
        return "�������Ѿ�׬��" + MONEY_D->money_str(n) + "��";
}

string ask_back()       //��Ҹı����⣬ȡ�ش�����Ʒ��
{
        object me, ob, *inv;
        int i, v3, v2, vt;

        me = this_player();
        ob = this_object();
        v3 = me->query("agent");        //������

        if (!v3) return "��û���Ұ�������������ɣ�";

        inv = all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
        if((string)me->query("id") == (string)inv[i]->query("agentby")){
                v2 = inv[i]->query("valued");
                vt = v2 - v3;
                inv[i]->delete("agentby");
                inv[i]->delete("valued");
                inv[i]->move(me);
                if(!wizardp(me)) me->delete("agent");   //if(!wizardp(me))..�����ã���Ϊ���������ܶණ��������:)
                ob->add("balance",vt);
                me->add("balance",-vt);

                message_vision(CYN"$N��$n���ͷ���ݸ�$nһ"+ inv[i]->query("unit") + inv[i]->name()+"��\n"NOR, ob, me);
                return "��Ȼ�㲻�����ˣ���������û�ȥ�ɣ�������Ҫ����"+MONEY_D->money_str(vt)+"��Ӷ��";
        }
        message_vision(CYN"$N����¶�����˵�΢Ц��������$n˵�������������Ķ����Ѿ�����ȥ�ˡ�\n"NOR, ob, me);
        return "Ҳ��������������ô����������";
}
