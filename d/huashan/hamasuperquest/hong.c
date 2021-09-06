
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int do_cry();
void create()
{
        set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "��ָ��ؤ");
        set("gender", "����");
        set("age", 75);
        set("long", 
"��һ�ų����������΢�룬���ִ�ţ������·���һ����һ��Ĵ����˲�����
ȴϴ�øɸɾ��������ϸ��Ÿ������Ĵ��«��\n");
        set("attitude", "peaceful");
        
        set("str", 35);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

        set("rank", 10);

        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 300);
        
        set("combat_exp", 3600000);
        set("score", 200000);
        set("death_times",180);

        set_skill("force", 400);             // �����ڹ�
        set_skill("huntian-qigong", 400);    // ��������
        set_skill("strike", 400);            // �����Ʒ�
        set_skill("xianglong-zhang", 400);   // ����ʮ����
        set_skill("hand", 360);              // �����ַ�
        set_skill("dodge", 400);             // ��������
        set_skill("xiaoyaoyou", 400);        // ��ң��
        set_skill("parry", 400);             // �����м�
        set_skill("stick", 400);             // ��������
        set_skill("dagou-bang", 400);        // �򹷰���
        set_skill("begging", 200);           // �л�����
        set_skill("checking", 200);          // ����;˵

        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("hand",  "shexing-diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        
        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 17, "����");
        setup();
        
            carry_object(ARMOR_D("bainayi"))->wear();
            carry_object(ARMOR_D("shoes"))->wear();

}

void init(){
        set_heart_beat(1);
        add_action("do_cry","cry");
}

void dest_ob(object ob,object me)
{
        object hong;
        me->move("/d/huashan/hamasuperquest/jueding5");
        hong = new("/d/huashan/hamasuperquest/hong2");
        hong->move("/d/huashan/hamasuperquest/jueding5");
        destruct(ob);

}

int do_cry()
{
        object me=this_player();
        object ob = this_object();
        object room,*inv;
        int i,j;

        j =0 ;
        room = environment(me);

        inv = all_inventory(room);
        for(i = 0,j=0; i < sizeof(inv); i++) {
                if( inv[i]->query("id")=="hong qigong" ) continue;
                j++;
       }
        if (j>1)
        command("say ������ô���ϻ�ɽ��ʲô���ˣ�\n");
        else if (me->query("oyf/hamagong") < 3) 
        {       
        
                command("haha");
                command("say С�޶�����ʲô�����¿�˵���㹫��������\n");
                tell_object(me,HIM"���������һ�ᣬ���߹���������Ծ���˻�ɽ������\n"NOR);

                call_out("dest_ob", 1, ob,me);
                
        }
        
}

