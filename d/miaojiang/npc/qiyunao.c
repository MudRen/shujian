// qiyunao

inherit NPC;
void create()
{
  
       set_name("���ư�", ({ "qi yunao", "qi" }));
       set("nickname", "�嶾����ʹ");
       set("long", 
               "�������嶾����ʹ��һ���ö��ı��켫Ϊ���¡�\n"
               "����һ������û���κα��顣\n");
        set("gender", "����");
       set("age", 36);
       set("attitude", "friendly");
       set("shen", -8000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
	set("unique", 1);
       set("startroom","/d/miaojiang/haozhai");
         set("env/wimpy", 60);
             set("chat_chance", 30);
             set("chat_msg", ({
               "���ư�����Ѳ������Χ�������ˡ�\n",
                 (: random_move :)
                    }) );
       set("max_qi", 1500);
       set("max_jing", 1500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 100);
       set("combat_exp", 900000);
 
       set_skill("force", 150);
        set_skill("yinyun-ziqi", 150);
       set_skill("dodge", 150);
      
       set_skill("tiyunzong", 160);
       set_skill("finger", 150);
       set_skill("qianzhu-wandushou", 160);
       set_skill("parry", 140);
       set_skill("sword", 140);
       set_skill("poison", 140);
       set_skill("literate", 80);
        map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("finger", "qianzhu-wandushou");
       map_skill("parry", "qianzhu-wandushou");
       prepare_skill("finger", "qianzhu-wandushou");
     

       set("inquiry", ([
//               "�ؼ�" : (: ask_me :),
               "Ԭ��־" : "����һֱ�һ��������þ�û�������ˡ�",
               "��ɳ��Ӱ" : "������������İ�����",
                
       ]));

//       wupin = random(2)?"/u/dubei/miaojiang/obj/txjdd":"/clone/weapon/blade";

       setup();
       carry_object(random(2)?"/d/miaojiang/obj/txjdd":"/clone/weapon/changjian");
       carry_object("/clone/armor/cloth")->wear();
 

}
 
 
 

 
