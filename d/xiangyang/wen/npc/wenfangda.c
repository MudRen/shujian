// /d/city/npc/wenfangda
// by daidai �������quest���
inherit NPC;
#include <ansi.h>
string ask_quest(); 
void create()
{
        set_name("�·���", ({ "wen fangda", "wen", "fangda" }));
        set("title", "�¼�����");
        set("long", 
        "�������¼����ϵ��ϴ��·��\n"
        "һ�����ݵ����ߣ�һ˫�۾�¶���ƻ���Ŀ�⡣\n");
        set("gender", "����");
        set("age", 66);
        set("attitude", "friendly");
        set("shen", -10000);
        set("str", 35);
        set("int", 30);
        set("con", 25);
        set("dex", 27);

        set("max_qi", 2000);
        set("eff_jingli", 1800);
        set("max_jing", 1800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 70);
        set("combat_exp", 1000000);
         

        set_skill("force", 150);
        set_skill("yijin-jing", 150);
        set_skill("dodge", 150);

        set_skill("shaolin-shenfa", 150);
        set_skill("cuff", 150);
        set_skill("wenjia-daofa", 160);
        set_skill("parry", 150);
        set_skill("blade", 150);
        set_skill("wenjia-quan", 150);
        set_skill("literate", 110);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "wenjia-quan");
        map_skill("parry", "wenjia-daofa");
        map_skill("blade", "wenjia-daofa");
        prepare_skill("cuff", "wenjia-quan");

        set("inquiry", ([
                "�����ɾ�" : (: ask_quest:),
                "��ѩ��" : (: ask_quest:),
        ]));

        setup(); 
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object("/clone/weapon/blade1")->wield();
}

string ask_quest()
{
        object me, ob, room;
        me = this_player();
        ob = this_object();

        if(me->query("quest/���߽���/pass"))    
        { 
           // ����quest������ �ҳ飡�� by daidai
           call_out("outwuguan",1,me);
           return "������ô֪����������ģ�";
        }
        if(!me->query_temp("quest/���߽���/start" ))
        {
           command("heng");
           return "�������¼ұ��ĳ��ˣ�";
        }
        message_vision(HIG"$N����¶����������ɫ��\n"NOR, ob);
        command("look "+me->query("id"));
        command("sigh");
        command("say ��ô˵����ǽ��߼����Ĵ����ˣ��������ˣ�");
         message_vision(HIC"$Nһ���֣����������ɡ�������$n�����䳡��ȥ��\n"NOR, ob, me);
        
        me->set_temp("quest/���߽���/start_kill",1);
        me->delete_temp("quest/���߽���/start");
//         me->move("/d/xiangyang/wen/quest/lianwu");
// Ϊ�˱����ж�����ͬʱ��quest by daidai
         room=new("/d/xiangyang/wen/quest/lianwu");
        me->move(room);
        return "��......";
}
void outwuguan(object me)
{
        object ob=this_object();
        object *inv;
        if(!me) return;
        command("ah");
        command("say ���ǽ����ɾ��Ǹ������Ĵ��ˣ����˰�������ɱ�����ˣ�");
        message_vision(HIR"ֻ��һȺ�Ҷ����������$N��ɱ������$N��Ķ��ӡ�\n"NOR, me);
        inv = filter_array(deep_inventory(me), (: userp :));
        if( sizeof(inv))
                inv->move(environment(ob));
        me->move("/d/xiangyang/ncx3");
}

