#include <ansi.h>

inherit ITEM;

void create()
{

       set_name(HIR"»ðÑæ"NOR, ({ "huo yan"}) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long", HIR"»ðÑæ¸ßÔ¼³ß£¬É«×÷´¿±Ì£¬¹íÆøÉ­É­£¬ºÍÑ°³£»ðÑæ´óÒì¡£\n"NOR );
               set("no_get", 1);
               set("value", 1);
               set("unit", "¶Ñ");
               set("fire_name", "»ðÑæ");
               set("weight", 30000);
               set("location", 1);
       }
       setup();
}

void init()
{
	if (base_name(environment())!="/d/xingxiu/ryd" && find_call_out("dest") < 0)
     		call_out("dest", 300);   
     	remove_call_out("change");
     	call_out("change", 50); 
}

string *fire_msg = ({
	BLU"»ðÑæ"NOR, RED"»ðÑæ"NOR, WHT"»ðÑæ"NOR, GRN"»ðÑæ"NOR, MAG"»ðÑæ"NOR,
	HIB"»ðÑæ"NOR, HIR"»ðÑæ"NOR, HIW"»ðÑæ"NOR, HIG"»ðÑæ"NOR, HIM"»ðÑæ"NOR,
	YEL"»ðÑæ"NOR, HIY"»ðÑæ"NOR,
});

void change()
{
    	tell_room(environment(this_object()),this_object()->name()+HIR"»íÈ»Ò»°µ£¬½Ó×Å»ð¹â±¬³¤£¬¾¹È»±äÁËÑÕÉ«£¬¿´ÆðÀ´¹ÖÒìÎÞ±È£¡\n"NOR);    
    	this_object()->set("name", fire_msg[random(sizeof(fire_msg))]);    
    	remove_call_out("change");
    	call_out("change", 50);  
}
 
void dest()
{
        tell_room(environment(this_object()),HIR"»ðÑæ½¥½¥µØÏ¨ÃðÁË¡£\n"NOR);
        destruct(this_object());
}
