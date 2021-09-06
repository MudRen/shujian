inherit NPC;

void create()
{
   set_name("大白雕", ({ "bai diao"}) );
   set("race", "野兽");
   set("age", 18);
   set("long", "生长在大草原中的一种猛禽。\n");
   
   set("str", 28);
   set("cor", 24);
   set("combat_exp",180000);
   set("env/wimpy",50);

   set("limbs", ({ "头部", "身体", "左翅", "右翅", "左脚","右脚" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
  "大白雕在云层中盘旋,双翅掠过重重白云.\n",
  "云层中一道闪电劈下,在你眼前闪过一道金光\n",

 }));


   setup();
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
         message_vision("你突然发现大白雕在万里高空，想下手可惜自己却没有生双翅膀？”\n", ob);
}