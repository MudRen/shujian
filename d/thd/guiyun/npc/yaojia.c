// Modified by Numa 19991018
// Fixed Tianqi-san too many 's problem
// Modified by Darken@SJ     slogan numa :)

#include "nadir.c"
inherit NPC;

// string ask_yao1();
string ask_yao2(); 
string ask_san();
string ask_dan();
object ob = this_object();
void create()
{
        set_name("������", ({"cheng yaojia", "cheng", "yaojia"}) );
        set("long", "���˶����������ţ������κ죬��Ǻ�Ц��ȴ��֪��������Щ��ô��\n");
        set("gender", "Ů��" );
        set("title", "��ׯ������");
        set("age", 24);
        set("attitude", "peaceful");
        set("str",25);
        set("int",25);
        set("con",27);
        set("dex",26);
        set("per",28);
        set("max_qi", 1000);
        set("max_jing", 450);
        set("neili", 800);
        set("max_neili", 800);
        set("eff_jingli",500);
        set("jiali", 30);
        set("combat_exp", 300000);
        set("unique", 1);

        set_skill("force", 100);
        set_skill("xiantian-gong", 90);
        set_skill("dodge", 90);
        set_skill("suibo-zhuliu", 90);
        set_skill("parry", 90);
        set_skill("strike", 100);
        set_skill("luoying-zhang", 90);
        set_skill("leg", 110);
        set_skill("xuanfeng-tui", 110);
        set_skill("sword", 90);
        set_skill("quanzhen-jianfa", 80);
        set_skill("literate", 100);
        set_skill("qimen-bagua", 60);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "suibo-zhuliu");
        map_skill("strike", "luoying-zhang");
        map_skill("leg", "xuanfeng-tui");
        map_skill("parry", "luoying-zhang");
        map_skill("sword", "quanzhen-jianfa");
        prepare_skill("strike", "luoying-zhang");

        set("shen_type", 1);
        set("shen", 200);
        set("class", "fighter");
        set("yao", 10);   
        set("san", 5);
        set("dan", 10);

        set("inquiry", ([
//                "���ɼ�����": (: ask_yao2 :),
                "�����赨ɢ": (: ask_san :),
                "�޳���": (: ask_dan :),
        ]) );

        setup();
        carry_object(__THD__"obj/white_cloth.c")->wear();
}

string ask_yao1()
{
        object ob = this_player();

        if (ob->query("family/family_name") != "�һ���")
                return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

        if (ob->query_condition("jingli_drug") > 0 )
                return RANK_D->query_respect(ob) + "�㲻�ǸճԹ�ҩ����ô����Ҫ�ˣ���ҩ����к����ˣ�����ʱ�������ɡ�";

        if (ob->query("max_jingli" ) < 200)
                return RANK_D->query_respect(ob) + "������������ҩ����к����ˣ�����ʱ�������ɡ�";

        if (present("sancai dan", ob))
                return RANK_D->query_respect(ob) + "���������ϲ����п�ҩ������ô����Ҫ�ˣ�����̰�����ᣡ";

        if (query("yao") < 1) return "�Բ���ҩ�Ѿ������ˣ��µĻ�δ������";
   
        new(__GUI__"obj/sancai-dan")->move(ob);

        add("yao", -1);

        message_vision("$N���һ�����ž۾�����\n", ob);
        return "�ðɣ���ҩ��֮���ף�������֮�˴��кô�����ҪС���ղغ��ˡ�";
}

string ask_yao2()
{
        object ob = this_player();

        if (ob->query("family/family_name") != "�һ���")
                return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

        if (ob->query_condition("medicine") > 0 )
                return RANK_D->query_respect(ob) + "�㲻�ǸճԹ�ҩ����ô����Ҫ�ˣ���ҩ����к����ˣ�����ʱ�������ɡ�";

        if (this_player()->query("max_neili") < 400)
                return RANK_D->query_respect(ob) + "������������ҩ����к����ˣ�����ʱ�������ɡ�";

        if (present("liuren wan", ob))
                return RANK_D->query_respect(ob) + "���������ϲ����п�ҩ������ô����Ҫ�ˣ�����̰�����ᣡ";

        if (query("yao") < 1) return "�Բ���ҩ�Ѿ������ˣ��µĻ�δ������";

        if(ob->query("max_neili")>= (ob->query_skill("force")* 10 + ob->query("con")* ob->query("age") +ob->query("combat_exp",1)/1000))
                     return RANK_D->query_respect(ob) + "��ҩ�Ѿ������ڰ��������������Ϊ�ˣ�";
        new("/clone/medicine/liuren-wan")->move(ob);

        add("yao", -1);

        message_vision("$N���һ�����ɼ����衣\n", ob);
        return "�ðɣ���ҩ��֮���ף�������֮�˴��кô�����ҪС���ղغ��ˡ�";
}

string ask_san()
{
        object ob = this_player(),obj;

        if (ob->query("family/family_name") != "�һ���")
                return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

        if (ob->query("combat_exp") < 500000)
                return RANK_D->query_respect(ob) + "����̫ǳ�����˲�����ʲô�����ġ�";

        if (this_player()->query("max_neili") < 1000)
                return RANK_D->query_respect(ob) + "������������ҩ����к����ˣ�����ʱ�������ɡ�";

        if (present("tianqi san", ob))
                return RANK_D->query_respect(ob) + "���������ϲ���������ô����Ҫ�ˣ�����̰�����ᣡ";
        if (ob->query_temp("thd/get_tianqi")>0)
                return RANK_D->query_respect(ob) + "��ղ�Ҫ������ô����Ҫ�ˣ�����̰�����ᣡ";

        if (query("san") < 1) return "�Բ���ҩ�Ѿ������ˣ��µĻ�δ������";

        obj = unew(__GUI__"obj/tianqi-san");
        if(!clonep(obj))
                return "�Բ���ҩ�Ѿ������ˣ��µĻ�δ������";

        obj->move(ob);
        ob->set_temp("thd/get_tianqi",1);

        add("san", -1);

        message_vision("$N���һ�������赨ɢ��\n", ob);
        return "�ðɣ���ҩ��֮���ף���ҪС���ղغ��ˡ�";
}

string ask_dan()
{
        object ob = this_player();

        if (ob->query("family/family_name") != "�һ���")
                return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

        if (ob->query("combat_exp") < 500000)
                return RANK_D->query_respect(ob) + "����̫ǳ�����˲�����ʲô�����ġ�";

        if (this_player()->query("max_neili") < 400)
                return RANK_D->query_respect(ob) + "������������ҩ����к����ˣ�����ʱ�������ɡ�";

        if (present("wuchang dan", ob))
                return RANK_D->query_respect(ob) + "���������ϲ����п�ҩ������ô����Ҫ�ˣ�����̰�����ᣡ";

        if (query("dan") < 1) return "�Բ���ҩ�Ѿ������ˣ��µĻ�δ������";

        new("/d/thd/guiyun/obj/wuchang-dan")->move(ob);

        add("dan", -1);

        message_vision("$N���һ���޳�����\n", ob);
        return "�ðɣ���ҩ��֮���ף���ҪС���ղغ��ˡ�";
}


