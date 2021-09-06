#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"降龙掌·排云飞扬残篇"NOR, ({ "paiyun canpian", "paiyun", "canpian"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long","这是一卷丐帮降龙掌的绝技残篇，你可以集齐五卷来合并(hebing)成一卷整篇。\n"
                );
                
                               set("value", 0);
                set("material", "skin");
                
        }
}
void init()
{
        
        add_action("do_hebing", "hebing");
}

int do_hebing(string arg)
{
int i,j,k;
object *inv, me = this_player();

if (!arg || arg == "")
return notify_fail("你想合并什么？\n");

if (arg != query("id")) 
return notify_fail("你想合并什么？\n");

if (this_player()->is_busy() || this_player()->is_fighting())
 return notify_fail("你正忙着呢。\n");

inv = all_inventory(me);
k=1;
j=  sizeof(inv);

while(j--){

if (inv[j] != this_object() && inv[j]->query("id") == query("id"))
k++;
}
 if(k < 5) 
         return notify_fail("你要合并的残篇不够五个！\n");  

 
message_vision(HIC "$N迫不及待地将"HIR""+chinese_number(k)+""HIC""+this_object()->query("unit")+"《"+this_object()->query("name")+""HIC"》合并成了一整篇。\n" NOR, me);  




if ( wizardp(me)) message_vision(HIM "kkkkkkk有"+k+"个\n" NOR, me);  
if ( wizardp(me)) message_vision(HIM "jjjjjjj有"+j+"个\n" NOR, me);  
        
j=sizeof(inv);
k=0;

while(j--){

if (inv[j] != this_object() && inv[j]->query("id") == query("id")&& k<4 )
{
        destruct(inv[j]);
  k++;
}
 
}

   destruct(this_object());                                 
 return 1;


}

