// Context	                Usage	                                Lifetime	        Scope	    Access Restrictions
// =====================================================================================================================================
// Inside a function	    Local static variable,                  Program duration	Function	Accessible only within function
//                          keeps its value across calls	       
// -------------------------------------------------------------------------------------------------------------------------------------
// File scope	            Restricts variable or                   Program duration	File	    Accessible only within file
//                          function to file (internal linkage)	    
// -------------------------------------------------------------------------------------------------------------------------------------
// Class static member	    Shared variable among                   Program duration	Class	    Accessible via ClassName::member
//                          all instances of the class	            
// -------------------------------------------------------------------------------------------------------------------------------------
// Class static function	Function that doesn’t require           Program duration	Class	    Can only access other static members
//                          an instance	                                                         
// -------------------------------------------------------------------------------------------------------------------------------------
